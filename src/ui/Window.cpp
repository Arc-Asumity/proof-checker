// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/Window.cpp
// Core of UI.

#include <glad/gl.h>
#include <utility>
#include <pc/ui/Window.hpp>

std::expected<Window, WindowError>
Window::Create(const char* title)
{
    Window self;

    if (glfwInit() == GLFW_FALSE) {
        return std::unexpected(WindowError::GlfwInitializationFailed);
    }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode =
        glfwGetVideoMode(monitor);

    if (monitor == nullptr || mode == nullptr) {
        glfwTerminate();
        return std::unexpected(
            WindowError::WindowCreationFailed
        );
    }

    self.width_ = mode->width * 2 / 3;
    self.height_ = mode->height *2 / 3;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* window = glfwCreateWindow(
        self.width_,
        self.height_,
        title,
        nullptr,
        nullptr
    );

    if (window == nullptr) {
        glfwTerminate();
        return std::unexpected(WindowError::WindowCreationFailed);
    }

    int monitorX = 0;
    int monitorY = 0;
    glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    glfwSetWindowPos(
        window,
        monitorX + (mode->width - self.width_) / 2,
        monitorY + (mode->height - self.height_) / 2
    );

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (gladLoadGL(glfwGetProcAddress) == 0) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return std::unexpected(
            WindowError::OpenGLLoaderInitializationFailed
        );
    }

    int framebufferWidth = 0;
    int framebufferHeight = 0;
    glfwGetFramebufferSize(
        window,
        &framebufferWidth,
        &framebufferHeight
    );

    glViewport(0, 0, self.width_, self.height_);

    glfwSetFramebufferSizeCallback(
        window,
        [](GLFWwindow*, const int w, const int h) {
            glViewport(0, 0, w, h);
        }
    );

    self.window_ = window;

    return self;
}

Window::~Window()
{
    if (window_ != nullptr)
    {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers() const
{
    glfwSwapBuffers(window_);
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(window_);
}

Window::Window(Window&& other) noexcept : window_(std::exchange(other.window_, nullptr))
{}

Window& Window::operator=(Window&& other) noexcept
{
    if (this == &other) {
        return *this;
    }

    if (window_ != nullptr) {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }

    window_ = std::exchange(other.window_, nullptr);

    return *this;
}

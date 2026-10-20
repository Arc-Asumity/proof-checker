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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* window = glfwCreateWindow(
        static_cast<int>(static_cast<float>(mode->width) * kScale),
        static_cast<int>(static_cast<float>(mode->height) * kScale),
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
        monitorX + static_cast<int>(static_cast<float>(mode->width) * (1 - kScale) / 2),
        monitorY + static_cast<int>(static_cast<float>(mode->height) * (1 - kScale) / 2)
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

    glViewport(0, 0, framebufferWidth, framebufferHeight);

    glfwSetWindowUserPointer(window, &self);
    glfwSetFramebufferSizeCallback(
        window,
        FramebufferSizeCallback
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

Window::Window(Window&& other) noexcept
    : window_(std::exchange(other.window_, nullptr))
    , width_(std::exchange(other.width_, 0))
    , height_(std::exchange(other.height_, 0))
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
    width_ = std::exchange(other.width_, 0);
    height_ = std::exchange(other.height_, 0);

    return *this;
}

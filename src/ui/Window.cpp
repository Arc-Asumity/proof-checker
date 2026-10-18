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

using namespace std;

expected<Window, WindowError>
Window::create(const int width, const int height, const char* title)
{
    if (glfwInit() == GLFW_FALSE) {
        return unexpected(WindowError::GlfwInitializationFailed);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* window = glfwCreateWindow(
        width,
        height,
        title,
        nullptr,
        nullptr
    );

    if (window == nullptr) {
        glfwTerminate();
        return unexpected(WindowError::WindowCreationFailed);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (gladLoadGL(glfwGetProcAddress) == 0)
    {
        glfwDestroyWindow(window);
        glfwTerminate();

        return unexpected(
            WindowError::OpenGLLoaderInitializationFailed
        );
    }

    glViewport(0, 0, width, height);

    return Window{window};
}

Window::~Window()
{
    if (window_ != nullptr)
    {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(window_);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(window_);
}

Window::Window(Window&& other) noexcept : window_(exchange(other.window_, nullptr))
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

    window_ = exchange(other.window_, nullptr);

    return *this;
}

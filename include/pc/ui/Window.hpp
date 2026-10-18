// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/UiCore.hpp
// Header file for Core of UI.

#pragma once

#include <expected>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

enum class WindowError
{
    GlfwInitializationFailed,
    WindowCreationFailed,
    OpenGLLoaderInitializationFailed,
};

class Window {
public:
    static std::expected<Window, WindowError>
    Create(int width, int height, const char* title);

    ~Window();

    static void PollEvents();
    void SwapBuffers() const;

    [[nodiscard]]
    bool ShouldClose() const;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;

private:
    GLFWwindow* window_{};

    Window() = default;
    explicit Window(GLFWwindow* window)
        : window_{window} {}
};

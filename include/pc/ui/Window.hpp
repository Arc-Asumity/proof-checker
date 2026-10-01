// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/UiCore.hpp
// Header file for Core of UI.

#pragma once

#include <expected>
#include <GLFW/glfw3.h>

using namespace std;

enum class WindowError
{
    GlfwInitializationFailed,
    WindowCreationFailed,
};

class Window {
public:
    static expected<Window, WindowError>
    create(int width, int height, const char* title);

    ~Window();

    static void pollEvents();
    void swapBuffers() const;

    [[nodiscard]]
    bool shouldClose() const;

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

// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Application.cpp
// Application.

#include <pc/core/Application.hpp>

#include <glad/gl.h>

std::expected<Application, WindowError>
Application::Create(const char* title)
{
    auto window = Window::Create(title);

    if (!window) {
        return std::unexpected(window.error());
    }

    return Application{
        std::move(*window),
    };
}

Application::Application(Window window)
    : window_(std::move(window)),
      render_(Renderer())
{
    render_.Init();
}

void Application::Run()
{
    glClearColor(0.08f, 0.09f, 0.12f, 1.0f);

    while (!window_.ShouldClose()) {
        Window::PollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        {
            Rect rect{
                .x = 0.0f,
                .y = 0.0f,
                .width = 1.0f,
                .height = 1.0f
            };

            root_.UpdateRect(rect);
            root_.Render(render_);
        }

        window_.SwapBuffers();
    }
}

Widget& Application::GetRoot()
{
    return root_;
}

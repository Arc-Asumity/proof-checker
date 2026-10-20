// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Application.cpp
// Application.

#include <glad/gl.h>

#include <pc/core/Application.hpp>
#include <pc/ui/widgets/Rectangle.hpp>

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
    glClearColor(0, 0, 0, 1);

    while (!window_.ShouldClose()) {
        Window::PollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        {
            root_ = MainWidget::MakeMain(
                MakeRectangle(Color{.r = 0.1f, .g = 0.1f, .b = 0.1f, .a = 1.0f}),
                MakeRectangle(Color{.r = 0.3f, .g = 0.3f, .b = 0.3f, .a = 1.0f})
            );
            root_.UpdateRect(MainWidget::kMain);
            root_.Render(render_);
        }

        window_.SwapBuffers();
    }
}

Widget& Application::GetRoot()
{
    return root_;
}

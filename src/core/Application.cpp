// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Application.cpp
// Application.

#include <pc/core/Application.hpp>

#include <glad/gl.h>

using namespace std;

expected<Application, WindowError>
Application::create()
{
    auto window = Window::create(
        1280,
        720,
        "Proof Checker"
    );

    if (!window) {
        return unexpected(window.error());
    }

    return Application{
        std::move(*window)
    };
}

Application::Application(Window window)
    : window_(std::move(window)),
      render_(make_unique<Render>())
{
    render_->init();
}

void Application::run()
{
    glViewport(0, 0, 1280, 720);
    glClearColor(0.08f, 0.09f, 0.12f, 1.0f);

    while (!window_.shouldClose()) {
        Window::pollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        render_->render();

        window_.swapBuffers();
    }
}

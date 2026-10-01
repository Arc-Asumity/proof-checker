// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Application.cpp
// Application.

#include <pc/core/Application.hpp>

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
    : window_(std::move(window))
{
}

void Application::run()
{
    while (!window_.shouldClose()) {
        Window::pollEvents();

        // TODO

        window_.swapBuffers();
    }
}

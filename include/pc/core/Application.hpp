// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/core/Application.hpp
// Header file for Application class.

#pragma once

#include <expected>
#include <memory>

#include <pc/ui/Window.hpp>
#include <pc/ui/Render.hpp>

using namespace std;

class Application
{
public:
    static expected<Application, WindowError> create();

    ~Application() = default;

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    Application(Application&&) noexcept = default;
    Application& operator=(Application&&) noexcept = default;

    void run();

private:
    explicit Application(Window window);

    Window window_;
    unique_ptr<Render> render_;
};

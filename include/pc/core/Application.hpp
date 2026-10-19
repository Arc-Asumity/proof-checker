// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/core/Application.hpp
// Header file for Application class.

#pragma once

#include <expected>

#include <pc/ui/Window.hpp>
#include <pc/ui/Widget.hpp>
#include <pc/ui/Renderer.hpp>

class Application
{
public:
    static std::expected<Application, WindowError> Create();

    ~Application() = default;

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    Application(Application&&) noexcept = default;
    Application& operator=(Application&&) noexcept = default;

    void Run();

    Widget& GetRoot();

private:
    explicit Application(Window window);

    Window window_;
    Widget root_;
    Renderer render_;
};

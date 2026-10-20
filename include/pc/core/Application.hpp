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
    static std::expected<Application, WindowError> Create(const char* title);

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

namespace MainWidget
{
    constexpr auto kMain = Rect{
        .x = 0.0f,
        .y = 0.0f,
        .width = 1.0f,
        .height = 1.0f
    };

    constexpr float kLayout = 0.05f;

    constexpr std::pair<Rect, Rect> kRectTopBottom = kMain.SplitY(kLayout, 1.0f - kLayout);
    constexpr Rect kRectTop = kRectTopBottom.first;
    constexpr Rect kRectBottom = kRectTopBottom.second;

    constexpr Widget MakeMain(Widget top_widget, Widget bottom_widget)
    {
        Widget result;
        std::vector<SubWidget>& sub = result.GetSub();
        sub.emplace_back(std::move(top_widget), kRectTop);
        sub.emplace_back(std::move(bottom_widget), kRectBottom);

        return result;
    }
}

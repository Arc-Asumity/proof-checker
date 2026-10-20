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

    Widget* GetPressedWidget(const Point& point);

private:
    explicit Application(Window window);

    Window window_;
    Widget root_;
    Renderer render_;

    bool is_press_ = false;
    Point press_position_;
    Widget* press_widget_;

};

namespace MainWidget
{
    constexpr auto kMain = Rect{
        .x = 0.0f,
        .y = 0.0f,
        .width = 1.0f,
        .height = 1.0f
    };

    constexpr int kLayout = 70;

    inline Widget MakeMain(const Window& window, Widget top_widget, Widget bottom_widget)
    {
        const float layout = window.NormalizeHeight(kLayout);
        auto [top, bottom] = kMain.SplitY(layout, 1.0f - layout);
        Widget result;
        top_widget.SetParent(&result);
        bottom_widget.SetParent(&result);
        std::vector<SubWidget>& sub = result.GetSub();
        sub.emplace_back(std::move(top_widget), top);
        sub.emplace_back(std::move(bottom_widget), bottom);

        return result;
    }
}

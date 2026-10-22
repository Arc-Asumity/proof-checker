// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/widgets/Main.hpp
// Header file for main widget of UI.

#pragma once

#include <pc/ui/Rect.hpp>
#include <pc/ui/Widget.hpp>

namespace MainWidget
{
    constexpr auto kMain = Rect{
        .x = 0.0f,
        .y = 0.0f,
        .width = 1.0f,
        .height = 1.0f
    };

    constexpr int kLayout = 70;

    inline Widget MakeMain(const int& height, Widget top_widget, Widget bottom_widget)
    {
        const float layout = static_cast<float>(kLayout) / static_cast<float>(height);
        auto [top, bottom] = kMain.SplitY(layout, 1.0f - layout);
        Widget result;
        top_widget.SetParent(&result);
        bottom_widget.SetParent(&result);
        std::vector<SubWidget>& sub = result.GetSub();
        sub.emplace_back(std::move(top_widget), top);
        sub.emplace_back(std::move(bottom_widget), bottom);

        return result;
    }

    inline void RemakeMain(const int& height, Widget* main)
    {
        std::vector<SubWidget>& sub = main->GetSub();
        if (sub.size() < 2)
            return;
        const float layout = static_cast<float>(kLayout) / static_cast<float>(height);
        auto [top, bottom] = kMain.SplitY(layout, 1.0f - layout);
        sub[0].rect_ = top;
        sub[1].rect_ = bottom;
    }
}

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
    constexpr int kMenuHeight = 70;

    inline Widget MakeMain(const int& height)
    {
        const float layout = static_cast<float>(kMenuHeight) / static_cast<float>(height);
        auto [top, bottom] = kFullRect.SplitY(layout, 1.0f - layout);
        Widget result;
        std::vector<SubWidget>& sub = result.GetSub();
        sub.emplace_back(Widget(), top);
        sub.emplace_back(Widget(), bottom);

        result.UpdateRect(kFullRect);

        return result;
    }

    inline void LoadSub(Widget& main, Widget top, Widget bottom)
    {
        std::vector<SubWidget> sub = main.GetSub();
        sub[0].widget_ = std::move(top);
        sub[0].widget_.SetParent(&main);
        sub[1].widget_ = std::move(bottom);
        sub[1].widget_.SetParent(&main);
    }

    inline void RemakeMain(const int& height, Widget* main)
    {
        std::vector<SubWidget>& sub = main->GetSub();
        if (sub.size() < 2)
            return;
        const float layout = static_cast<float>(kMenuHeight) / static_cast<float>(height);
        auto [top, bottom] = kFullRect.SplitY(layout, 1.0f - layout);
        sub[0].rect_ = top;
        sub[1].rect_ = bottom;

        main->UpdateRect(kFullRect);
    }
}

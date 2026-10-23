// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/widgets/Menu.hpp
// Header file for menu widget of UI.

#pragma once

#include <iostream>
#include <pc/ui/Widget.hpp>

namespace MenuWidget
{
    constexpr int kControlWidth = 100;

    inline Widget MakeMenu(const int& width)
    {
        const float layout = static_cast<float>(kControlWidth) / static_cast<float>(width);
        const std::array layouts = {1.0f - 3 * layout ,layout ,layout ,layout};
        std::array<Rect, 4> rects = kFullRect.SplitXs(layouts);
        for (auto& rect_item : rects)
        {
            std::cout << rect_item << std::endl;
        }
    }
}

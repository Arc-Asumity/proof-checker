// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Widget.hpp
// Header file for widget of UI.

#pragma once

#include <vector>

#include <pc/ui/Rect.hpp>
#include <pc/ui/Base.hpp>

using namespace std;

class WidgetPart
{
public:
    void updateRect(Rect& rect);
    void render();

private:
    PointSet points_{};
    PointSet points_temporary_{};

};

class Widget
{
public:
    Widget() = default;

    void updateRect(Rect& rect);
    void render();

private:
    vector<WidgetPart> parts_{};

    PointSet hits_{};
    PointSet hits_temporary_{};

    vector<Widget> sub_{};
    float* rects_{};

};

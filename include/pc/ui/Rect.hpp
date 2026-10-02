// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Rect.hpp
// Header file for rect of UI.

#pragma once
#include <vector>

using namespace std;

struct Rect
{
    float x;
    float y;
    float width;
    float height;

    [[nodiscard]] pair<Rect, Rect>
    split_x(float left, float right) const;
    [[nodiscard]] pair<Rect, Rect>
    split_y(float top, float bottom) const;

    [[nodiscard]] vector<Rect>
    split_xs(vector<float> xs) const;
    [[nodiscard]] vector<Rect>
    split_ys(vector<float> ys) const;

    template<size_t N>
    array<Rect, N> split_xs(array<float, N> xs);
    template<size_t N>
    array<Rect, N> split_ys(array<float, N> ys);
};

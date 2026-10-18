// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Rect.hpp
// Header file for rect of UI.

#pragma once
#include <vector>

#include <pc/ui/Base.hpp>

using namespace std;

struct Rect
{
    float x;
    float y;
    float width;
    float height;

    [[nodiscard]] pair<Rect, Rect>
    SplitX(float left, float right) const;
    [[nodiscard]] pair<Rect, Rect>
    SplitY(float top, float bottom) const;

    [[nodiscard]] vector<Rect>
    SplitXs(const vector<float>& xs) const;
    [[nodiscard]] vector<Rect>
    SplitYs(const vector<float>& ys) const;

    template<const size_t N>
    array<Rect, N> SplitXs(const array<float, N>& xs) const;
    template<const size_t N>
    array<Rect, N> SplitYs(const array<float, N>& ys) const;

    [[nodiscard]] vector<Rect>
    SplitXs(const float* xs, size_t size) const;
    [[nodiscard]] vector<Rect>
    SplitYs(const float* ys, size_t size) const;

    [[nodiscard]] Point
    translate(float current_x, float current_y) const;
    [[nodiscard]] Point
    translate(Point point) const;

private:
    void SplitXs(const float* xs, Rect* result, size_t size) const;
    void SplitYs(const float* ys, Rect* result, size_t size) const;
};

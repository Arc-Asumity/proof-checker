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

struct Rect
{
    float x;
    float y;
    float width;
    float height;

    [[nodiscard]] std::pair<Rect, Rect>
    SplitX(float left, float right) const;
    [[nodiscard]] std::pair<Rect, Rect>
    SplitY(float top, float bottom) const;

    [[nodiscard]] std::vector<Rect>
    SplitXs(const std::vector<float>& xs) const;
    [[nodiscard]] std::vector<Rect>
    SplitYs(const std::vector<float>& ys) const;


    template <const size_t N>
    std::array<Rect, N> SplitXs(const std::array<float, N>& xs) const
    {
        std::array<Rect, N> result;
        SplitXs(xs.data(), result.data(), N);
        return result;
    }
    template <const size_t N>
    std::array<Rect, N> SplitYs(const std::array<float, N>& ys) const
    {
        std::array<Rect, N> result;
        SplitYs(ys.data(), result.data(), N);
        return result;
    }

    [[nodiscard]] std::vector<Rect>
    SplitXs(const float* xs, size_t size) const;
    [[nodiscard]] std::vector<Rect>
    SplitYs(const float* ys, size_t size) const;

    [[nodiscard]] Point
    Translate(float current_x, float current_y) const;
    [[nodiscard]] Point
    Translate(Point point) const;

    Rect operator*(const Rect& other) const;

private:
    void SplitXs(const float* xs, Rect* result, size_t size) const;
    void SplitYs(const float* ys, Rect* result, size_t size) const;
};

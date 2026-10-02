// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/Rect.cpp
// Rect of UI.

#include <algorithm>
#include <numeric>
#include <pc/ui/Rect.hpp>

using namespace std;

pair<Rect, Rect> Rect::split_x(const float left, const float right) const
{
    Rect left_rect = *this;
    left_rect.width = left * this->width / (left + right);
    Rect right_rect = *this;
    right_rect.width = this->width - left_rect.width;
    right_rect.x = left_rect.x + left_rect.width;
    return {left_rect, right_rect};
}

pair<Rect, Rect> Rect::split_y(const float top, const float bottom) const
{
    Rect top_rect = *this;
    top_rect.height = top * this->height / (top + bottom);
    Rect bottom_rect = *this;
    bottom_rect.height = this->height - top_rect.height;
    bottom_rect.y = top_rect.y + top_rect.height;
    return {top_rect, bottom_rect};
}

vector<Rect> Rect::split_xs(vector<float> xs) const
{
    float local_x = this->x;
    const float coefficient = this->width / accumulate(xs.begin(), xs.end(), 0.0f);
    vector<Rect> result;
    for (const float current_x : xs)
    {
        const float current_width = current_x * coefficient;
        result.push_back(Rect{.x = local_x, .y = this->y, .width = current_width, .height = this->height});
        local_x += current_width;
    }
    return result;
}

vector<Rect> Rect::split_ys(vector<float> ys) const
{
    float local_y = this->y;
    const float coefficient = this->height / accumulate(ys.begin(), ys.end(), 0.0f);
    vector<Rect> result;
    for (const float current_y : ys)
    {
        const float current_height = current_y * coefficient;
        result.push_back(Rect{.x = this->x, .y = local_y, .width = this->width, .height = current_height});
        local_y += current_height;
    }
    return result;
}

template <size_t N>
array<Rect, N> Rect::split_xs(array<float, N> xs)
{
    float local_x = this->x;
    const float coefficient = this->width / accumulate(xs.begin(), xs.end(), 0.0f);
    array<Rect, N> result;
    for (size_t i = 0; i < xs.size(); i++)
    {
        const float current_width = xs[i] * coefficient;
        result[i](Rect{.x = local_x, .y = this->y, .width = current_width, .height = this->height});
        local_x += current_width;
    }
    return result;
}

template <size_t N>
array<Rect, N> Rect::split_ys(array<float, N> ys)
{
    float local_y = this->y;
    const float coefficient = this->height / accumulate(ys.begin(), ys.end(), 0.0f);
    array<Rect, N> result;
    for (size_t i = 0; i < ys.size(); i++)
    {
        const float current_height = ys[i] * coefficient;
        result[i](Rect{.x = this->x, .y = local_y, .width = this->width, .height = current_height});
        local_y += current_height;
    }
    return result;
}

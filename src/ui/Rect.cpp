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

std::pair<Rect, Rect> Rect::SplitX(const float left, const float right) const
{
    Rect left_rect = *this;
    left_rect.width = left * this->width / (left + right);
    Rect right_rect = *this;
    right_rect.width = this->width - left_rect.width;
    right_rect.x = left_rect.x + left_rect.width;
    return {left_rect, right_rect};
}

std::pair<Rect, Rect> Rect::SplitY(const float top, const float bottom) const
{
    Rect top_rect = *this;
    top_rect.height = top * this->height / (top + bottom);
    Rect bottom_rect = *this;
    bottom_rect.height = this->height - top_rect.height;
    bottom_rect.y = top_rect.y + top_rect.height;
    return {top_rect, bottom_rect};
}

std::vector<Rect> Rect::SplitXs(const std::vector<float>& xs) const
{
    std::vector<Rect> result(xs.size());
    SplitXs(xs.data(), result.data(), xs.size());
    return result;
}

std::vector<Rect> Rect::SplitYs(const std::vector<float>& ys) const
{
    std::vector<Rect> result(ys.size());
    SplitYs(ys.data(), result.data(), ys.size());
    return result;
}

std::vector<Rect> Rect::SplitXs(const float* xs, const size_t size) const
{
    std::vector<Rect> result(size);
    SplitXs(xs, result.data(), size);
    return result;
}

std::vector<Rect> Rect::SplitYs(const float* ys, const size_t size) const
{
    std::vector<Rect> result(size);
    SplitYs(ys, result.data(), size);
    return result;
}

void Rect::SplitXs(const float* xs, Rect* result, const size_t size) const
{
    if (size == 0) return;
    const float sum = std::accumulate(xs, xs + size, 0.0f);
    if (sum <= 0.0f) return;
    float local_x = this->x;
    const float coefficient = this->width / sum;
    for (const float* i = xs; i < xs + size; i++)
    {
        const float current_width = *i * coefficient;
        *result = Rect{.x = local_x, .y = this->y, .width = current_width, .height = this->height};
        result++;
        local_x += current_width;
    }
}

void Rect::SplitYs(const float* ys, Rect* result, const size_t size) const
{
    if (size == 0) return;
    const float sum = std::accumulate(ys, ys + size, 0.0f);
    if (sum <= 0.0f) return;
    float local_y = this->y;
    const float coefficient = this->height / sum;
    for (const float* i = ys; i < ys + size; i++)
    {
        const float current_height = *i * coefficient;
        *result = Rect{.x = this->x, .y = local_y, .width = this->width, .height = current_height};
        result++;
        local_y += current_height;
    }
}

Point Rect::Translate(const float current_x, const float current_y) const
{
    Point result{};
    result.x = this->x + this->width * current_x;
    result.y = this->y + this->height * current_y;
    return result;
}

Point Rect::Translate(const Point point) const
{
    return Translate(point.x, point.y);
}

// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/Widget.cpp
// Widget of UI.

#include <algorithm>
#include <ranges>
#include <utility>
#include <pc/ui/Widget.hpp>
#include <pc/ui/Base.hpp>

WidgetPart::WidgetPart(PointSet points)
    : points_(std::move(points))
{}

Widget::Widget(std::vector<WidgetPart> parts)
    : parts_(std::move(parts))
{}

void WidgetPart::UpdateRect(Rect& rect)
{
    points_temporary_.resize(points_.size());
    std::ranges::transform(
        points_,
        points_temporary_.begin(),
        [&rect](const Point& point)
        {
            return rect.Translate(point);
        }
    );
}

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

using namespace std;

WidgetPart::WidgetPart(PointSet points)
    : points_(std::move(points))
{}

Widget::Widget(vector<WidgetPart> parts)
    : parts_(std::move(parts))
{}

void WidgetPart::updateRect(Rect& rect)
{
    points_temporary_.resize(points_.size());
    ranges::transform(
        points_,
        points_temporary_.begin(),
        [&rect](const Point& point)
        {
            return rect.translate(point);
        }
    );
}

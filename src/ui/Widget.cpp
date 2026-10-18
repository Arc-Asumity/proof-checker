// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/Widget.cpp
// Widget of UI.

#include <algorithm>
#include <ranges>
#include <pc/ui/Widget.hpp>
#include <pc/ui/Base.hpp>

using namespace std;

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



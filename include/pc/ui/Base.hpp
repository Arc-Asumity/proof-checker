// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Base.hpp
// Header file for base of UI.

#pragma once

#include <vector>

struct Point
{
    float x;
    float y;
};

using PointSet = std::vector<Point>;

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    return os << "Point{ x=" << point.x
              << ", y=" << point.y
              << " }";
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<Point>& points)
{
    return os << points;
}

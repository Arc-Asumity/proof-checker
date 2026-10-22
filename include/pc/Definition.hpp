// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/Definition.hpp
// Header file for constant variant.

#pragma once

#include <pc/ui/Base.hpp>

namespace document
{
    constexpr size_t kGapFillSize = 8;
    constexpr size_t kGapEmptySize = 16;
    constexpr size_t kGapSize = kGapFillSize + kGapEmptySize;

}

namespace mathematics
{
    inline float Cross(const Point& a, const Point& b, const Point& p)
    {
        return (b.x - a.x) * (p.y - a.y)
             - (b.y - a.y) * (p.x - a.x);
    }

    inline bool ContainsConvexPolygon(const PointSet& polygon, const Point& p)
    {
        if (polygon.size() < 3)
            return false;

        for (std::size_t i = 0; i < polygon.size(); ++i)
        {
            const Point& a = polygon[i];

            if (const Point& b = polygon[(i + 1) % polygon.size()]; Cross(a, b, p) < 0.0f)
                return false;
        }

        return true;
    }
}

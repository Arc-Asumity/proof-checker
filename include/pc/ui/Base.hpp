// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Base.hpp
// Header file for base of UI.

#pragma once
#include <vector>

using namespace std;

struct Point
{
    float x;
    float y;
};

using PointSet = vector<Point>;

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

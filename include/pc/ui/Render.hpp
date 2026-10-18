// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Render.hpp
// Header file for render of UI.

#pragma once
#include <pc/ui/Widget.hpp>

using namespace std;

#include <vector>

class Render
{
public:
    void render();

private:
    Widget root_;
};

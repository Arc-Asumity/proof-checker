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

class Render
{
public:
    Render() = default;
    ~Render();

    Render(const Render&) = delete;
    Render& operator=(const Render&) = delete;

    void init();
    void render();
    void renderPolygon(PointSet& points);

private:
    unsigned int program_{};
    unsigned int vao_{};
    unsigned int vbo_{};

    Widget root_;
};

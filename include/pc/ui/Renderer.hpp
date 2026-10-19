// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Renderer.hpp
// Header file for render of UI.

#pragma once

#include <pc/ui/Base.hpp>

class Renderer
{
public:
    Renderer() = default;
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) noexcept = default;
    Renderer& operator=(Renderer&&) noexcept = default;

    void Init();
    void RenderPolygon(const PointSet& points) const;

private:
    unsigned int program_{};
    unsigned int vao_{};
    unsigned int vbo_{};
};

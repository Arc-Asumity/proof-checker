// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/Widget.hpp
// Header file for widget of UI.

#pragma once

#include <vector>

#include <pc/ui/Rect.hpp>
#include <pc/ui/Base.hpp>
#include <pc/ui/Renderer.hpp>

struct SubWidget;

class WidgetPart
{
public:
    explicit WidgetPart(PointSet points, Color color);

    void UpdateRect(const Rect& rect);
    void Render(const Renderer& renderer) const;

private:
    PointSet points_{};
    PointSet points_temporary_{};

    Color color_;

};

class Widget
{
public:
    Widget() = default;

    explicit Widget(std::vector<WidgetPart> parts);

    std::vector<SubWidget>& GetSub();

    void UpdateRect(const Rect& rect);
    void Render(Renderer& renderer);

private:
    std::vector<WidgetPart> parts_{};

    PointSet hits_{};
    PointSet hits_temporary_{};

    std::vector<SubWidget> sub_{};

};

struct SubWidget
{
    Widget widget_;
    const Rect& rect_;

    SubWidget(Widget widget, const Rect& rect);
};

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

WidgetPart::WidgetPart(PointSet points, const Color color)
    : points_(std::move(points))
    , color_(color)
{}

Widget::Widget(std::vector<WidgetPart> parts)
    : parts_(std::move(parts))
{}

std::vector<SubWidget>& Widget::GetSub()
{
    return sub_;
}

void WidgetPart::UpdateRect(const Rect& rect)
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

void WidgetPart::Render(const Renderer& renderer) const
{
    renderer.RenderPolygon(points_temporary_, color_);
}

void Widget::UpdateRect(const Rect& rect_origin)
{
    for (WidgetPart& part : parts_) {
        part.UpdateRect(rect_origin);
    }

    for (auto& [widget, rect] : sub_) {
        Rect rect_child = rect_origin * rect;
        widget.UpdateRect(rect_child);
    }
}

void Widget::Render(Renderer& renderer)
{
    for (WidgetPart& part : parts_) {
        part.Render(renderer);
    }

    for (auto& [widget, _rect] : sub_) {
        widget.Render(renderer);
    }
}

SubWidget::SubWidget(Widget  widget, Rect& rect)
    : widget(std::move(widget))
    , rect(rect)
{}

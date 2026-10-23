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
#include <pc/Definition.hpp>

WidgetPart::WidgetPart(PointSet points, const Color color)
    : points_(std::move(points))
    , color_(color)
{}

Widget::Widget(std::vector<WidgetPart> parts)
    : parts_(std::move(parts))
{}

Widget::Widget(std::vector<WidgetPart> parts, PointSet hits)
    : parts_(std::move(parts))
    , hits_(std::move(hits))
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

void WidgetPart::ChangeColor(const Color& color)
{
    color_ = color;
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

    hits_temporary_.resize(hits_.size());
    std::ranges::transform(
        hits_,
        hits_temporary_.begin(),
        [&rect_origin](const Point& point)
        {
            return rect_origin.Translate(point);
        }
    );
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

void Widget::SetParent(Widget* parent)
{
    parent_ = parent;
}

Widget* Widget::GetPressedWidget(const Point& point)
{
    for (auto& [widget, rect] : sub_)
        if (mathematics::ContainsConvexPolygon(widget.hits_temporary_, point))
            return widget.GetPressedWidget(point);
    return this;
}

void Widget::HandlePressed(const Point& point)
{
    parts_[0].ChangeColor(Color{.r = 1.0f, .g = 1.0f, .b = 1.0f, .a = 1.0f});
}

SubWidget::SubWidget(Widget widget, const Rect rect)
    : widget_(std::move(widget))
    , rect_(rect)
{}

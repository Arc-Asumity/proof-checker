// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/widgets/Rectangle.cpp
// Rectangle widget factory.

#include <pc/ui/widgets/Rectangle.hpp>

Widget MakeRectangle()
{
    return Widget{
        std::vector{
            WidgetPart{
                PointSet{
                    {.x = 0.0f, .y = 0.0f},
                    {.x = 1.0f, .y = 0.0f},
                    {.x = 1.0f, .y = 1.0f},
                    {.x = 0.0f, .y = 1.0f}
                },
                Color{
                    .r = 0.2f,
                    .g = 0.5f,
                    .b = 0.8f,
                    .a = 1.0f
                }
            }
        }
    };
}

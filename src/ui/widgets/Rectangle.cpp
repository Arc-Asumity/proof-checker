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
        vector{
            WidgetPart{
                PointSet{
                    {.x = 0.0f, .y = 0.0f},
                    {.x = 1.0f, .y = 0.0f},
                    {.x = 1.0f, .y = 1.0f},
                    {.x = 0.0f, .y = 1.0f}
                }
            }
        }
    };
}

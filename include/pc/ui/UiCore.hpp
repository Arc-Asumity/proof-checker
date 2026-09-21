// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/ui/UiCore.hpp
// Header file for Core of UI.

#pragma once

#include <GLFW/glfw3.h>

class Session
{
    GLFWwindow* window_ = nullptr;
    float scale_ = 0;
public:
    int init();
    [[nodiscard]] int runGui() const;
};

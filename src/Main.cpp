// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/Main.cpp
// Main of ProofChecker.

#include <pc/core/Application.hpp>
#include <pc/ui/widgets/Rectangle.hpp>

int main(const int argc, char* argv[])
{
    auto application = Application::Create();

    if (!application) {
        return 1;
    }

    Widget& root = application->GetRoot();

    auto rect = Rect{.x = 0.25f, .y = 0.25f, .width = 0.5f, .height = 0.5f};
    root.GetSub().emplace_back(MakeRectangle(), rect);

    application->Run();

    return 0;
}

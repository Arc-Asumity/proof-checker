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
    root.GetSub().push_back(MakeRectangle());

    application->Run();

    return 0;
}

// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/Main.cpp
// Main of ProofChecker.

#include <pc/core/Application.hpp>

int main(const int argc, char* argv[])
{
    auto application = Application::Create("Proof Checker");

    if (!application) {
        return 1;
    }

    application->Run();

    return 0;
}

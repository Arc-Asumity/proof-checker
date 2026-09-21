// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/Main.cpp
// Main of ProofChecker.

#include <pc/ui/UiCore.hpp>

int main(const int argc, char* argv[])
{
    auto session = Session();
    session.init();
    return session.runGui();
}

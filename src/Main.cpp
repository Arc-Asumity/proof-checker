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
    auto application = Application::Create();

    if (!application) {
        return 1;
    }

    Widget& root = application->GetRoot();
    root.GetSub().push_back(Widget({
          WidgetPart{
              PointSet{
                  {.x = 0.25f, .y = 0.25f},
                  {.x = 0.75f, .y = 0.25f},
                  {.x = 0.75f, .y = 0.75f},
                  {.x = 0.25f, .y = 0.75f}
              }
          }
      }));

    application->Run();

    return 0;
}

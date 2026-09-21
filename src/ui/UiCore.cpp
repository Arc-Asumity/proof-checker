// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/ui/UiCore.cpp
// Core of UI.

#include <pc/ui/UiCore.hpp>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

int Session::init()
{
    if (!glfwInit()) return -1;
    window_ = glfwCreateWindow(1920, 1080, "Proof Checker", nullptr, nullptr);
    float scale_x, scale_y;
    glfwGetWindowContentScale(window_, &scale_x, &scale_y);
    scale_ = scale_x * 1.5f;
    if (!window_)
    {
        glfwTerminate();
        return -1;
    }
    return 0;
}

int Session::runGui() const
{
    glfwMakeContextCurrent(window_);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    const ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    while (!glfwWindowShouldClose(window_))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();

            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window_);
    }

    glfwDestroyWindow(window_);

    glfwTerminate();

    return 0;
}

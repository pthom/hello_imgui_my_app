#include "hello_imgui/hello_imgui.h"

void Gui()
{
    // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
    // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
    static char text[1024 * 16] =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et "
        "dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex"
        "ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
        "nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim "
        "id est laborum.";

    static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
    ImGui::CheckboxFlags("ImGuiInputTextFlags_ReadOnly", (unsigned int*)&flags, ImGuiInputTextFlags_ReadOnly);
    ImGui::CheckboxFlags("ImGuiInputTextFlags_AllowTabInput", (unsigned int*)&flags, ImGuiInputTextFlags_AllowTabInput);
    ImGui::CheckboxFlags("ImGuiInputTextFlags_CtrlEnterForNewLine", (unsigned int*)&flags, ImGuiInputTextFlags_CtrlEnterForNewLine);
    ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);

}

int main(int, char **)
{
  HelloImGui::RunnerParams runnerParams;
  runnerParams.callbacks.ShowGui = Gui;
  HelloImGui::Run(runnerParams);
  return 0;
}

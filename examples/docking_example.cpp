#include "hello_imgui/hello_imgui.h"
#include "hello_imgui/widgets/logger.h"

HelloImGui::Widgets::Logger logger;

void MainGui()
{
    ImGui::Text("Main");
    if (ImGui::Button("Click"))
        logger.warning("Click!");
}
void ShowCommandsPanel()
{
    ImGui::Text("ShowCommandsPanel");
    if (ImGui::Button("Command"))
        logger.warning("Command!");
}

int main(int, char **)
{
    HelloImGui::RunnerParams runnerParams;
    runnerParams.imGuiWindowParams.defaultImGuiWindowType =
        HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace;


    runnerParams.dockingParams.dockingSplits =
    {
        // First, add a bottom space named "LogsSpace" 
        // whose height is 25% of the app height
        // This will split the preexisting default dockspace "MainDockSpace"
        // in two parts.
        { "MainDockSpace", "LogsSpace", ImGuiDir_Down, 0.25 },
        // Then, add a space to the left which occupies a column
        // whose width is 25% of the app height
        { "MainDockSpace", "LeftSpace", ImGuiDir_Left, 0.25 }
        // We now have three spaces: "MainDockSpace", "BottomSpace", and "LeftSpace"
    };
    runnerParams.dockingParams.dockableWindows =
    {
        // A Window named "Main" will be placed in "MainDockSpace".
        // Its Gui is provided by the VoidFunction "MainGui"
        {"Main", "MainDockSpace", MainGui},
        // A Log  window named "Logs" will be placed in "LogsSpace" 
        // see ../external/hello_imgui/src/hello_imgui/widgets/logger.h
        logger,
        // A Command panel named "Commands" will be placed in "LeftSpace".
        // Its Gui is provided by the VoidFunction "ShowCommandsPanel"
        {"Commands", "LeftSpace", ShowCommandsPanel}
    };

    runnerParams.imGuiWindowParams.showMenuBar = true;
    runnerParams.imGuiWindowParams.showStatusBar = true;

    HelloImGui::Run(runnerParams);
  return 0;
}

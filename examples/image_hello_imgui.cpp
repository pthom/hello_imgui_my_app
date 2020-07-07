#include "hello_imgui/hello_imgui.h"

void Gui()
{
    static auto image = HelloImGui::ImageGl::FactorImage("smiley.png");
    image->Draw(ImVec2(300.f, 300.f));
}

int main(int, char **)
{
  HelloImGui::RunnerParams runnerParams;
  runnerParams.callbacks.ShowGui = Gui;
  HelloImGui::Run(runnerParams);
  return 0;
}

#include "hello_imgui/hello_imgui.h"
int main(int , char *[])
{
    HelloImGui::Run(
        []{ ImGui::Text("Hello, world!"); },
        { 200.f, 50.f },
        "Hello!" );
}

#include "hello_imgui/hello_imgui.h"
#include <future>
#include <thread>
#include <chrono>
#include <fplus/fplus.hpp>

struct AppContext
{
    fplus::stopwatch mTimer;
    int mCounter = 0;
    std::future<int> mAnswerToEverything;
};

template<typename R>
bool is_ready(std::future<R> const& f)
{ return f.wait_for(std::chrono::seconds(0)) == std::future_status::ready; }


int answerToEverything()
{
    using namespace std::literals;
    std::this_thread::sleep_for(3s);
    return 42;
}

void Gui(AppContext & appContext)
{
    auto f = []() {
        int v = answerToEverything();
        return v;
    };

    if (ImGui::Button("Click me"))
        ++appContext.mCounter;

    if (ImGui::Button("Compute Answer"))
        appContext.mAnswerToEverything = std::async(answerToEverything);


    ImGui::Text("counter=%i", appContext.mCounter);

    ImGui::Text("Time: %.2f", appContext.mTimer.elapsed());
}

int main(int, char **)
{
  AppContext appContext;
  auto guiWithContext = [&appContext]() {
      Gui(appContext);
  };

  HelloImGui::RunnerParams runnerParams;
  runnerParams.callbacks.ShowGui = guiWithContext;
  HelloImGui::Run(runnerParams);
  return 0;
}

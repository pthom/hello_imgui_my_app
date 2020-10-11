cmake_minimum_required(VERSION 3.10)
project(my_app LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)

# Step 1: Add hello_imgui as a subdirectory
add_subdirectory(external/hello_imgui)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${HELLOIMGUI_BASEPATH}/hello_imgui_cmake)

# Step 2: include hello_imgui_add_app
include(hello_imgui_add_app)

# Step 3 (emscripten only): include hello_imgui_emscripten_global_options
if (EMSCRIPTEN)
    include(${HELLOIMGUI_BASEPATH}/hello_imgui_cmake/emscripten/hello_imgui_emscripten_global_options.cmake)
endif()

# Step 4: declare your app
hello_imgui_add_app(hello hello.cpp)

# For gitpod "instant demo only"
add_subdirectory(examples)

add_subdirectory(test)

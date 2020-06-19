# Hello ImGui Demo app

This repository demonstrates how to create a new application using ImGui.

hello_imgui is a submodule: 
````bash
git submodule add https://github.com/pthom/hello_imgui.git external/hello_imgui
````

# Compile for desktop

See [compile_sdl_desktop.sh](compile_sdl_desktop.sh)

````bash
# Step 1: update submodule recursively
git submodule update --init --recursive

# Step 2: install third paties via vcpkg
./external/hello_imgui/tools/vcpkg_install_third_parties.sh

# Step 3: run cmake using vcpkg toolchain
mkdir build_sdl && cd build_sdl
cmake .. -DCMAKE_TOOLCHAIN_FILE=../external/hello_imgui/vcpkg/scripts/buildsystems/vcpkg.cmake -DHELLOIMGUI_USE_SDL_OPENGL3=ON

# Step 4: build
make -j 4

# Step 5: run the app
./hello
````

# Compile for emscripten

````bash
# Step 1: install emscripten
./external/hello_imgui/tools/emscripten/install_emscripten.sh

# Step 2: add emscripten to your PATH
source ~/emsdk/emsdk_env.sh

# Step 3: run cmake using vcpkg toolchain
mkdir build_emscripten && cd build_emscripten
emcmake cmake .. 

# Step 4: build
make -j 4

# Step 5: run a web server
python3 -m http.server

# Step 6: Open a browser and open the url
# http://localhost:8000/hello.html
````


# Compile for iOS

````bash
# Step 1: build sdl
./external/hello_imgui/tools/ios/sdl_compile_ios.sh

# Step 2: set your Apple Development Team Id
export CMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM=XA68U4C3Y7

# Step : cmake
mkdir build_ios
cd build_ios
cmake .. \
  -GXcode \
  -DCMAKE_TOOLCHAIN_FILE=../external/hello_imgui/hello_imgui_cmake/ios-cmake/ios.toolchain.cmake \
  -DHELLOIMGUI_USE_SDL_OPENGL3=ON \
  -DPLATFORM=OS64 \
  -DENABLE_BITCODE=OFF \
  .. 

# Step : open Xcode, build and run
open my_app.xcodeproj

````


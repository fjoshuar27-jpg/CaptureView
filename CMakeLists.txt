cmake_minimum_required(VERSION 3.22)

project(
    CaptureView
    VERSION 0.1.0
    DESCRIPTION "Low latency capture card viewer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CaptureView
    Source/Main.cpp
    Source/Core/Application.cpp
    Source/Core/Logger.cpp
    Source/Platform/Window.cpp
 "Source/Rendering/Renderer.cpp" "Source/Graphics/GraphicsDevice.cpp")
target_include_directories(CaptureView PRIVATE
    Include
)
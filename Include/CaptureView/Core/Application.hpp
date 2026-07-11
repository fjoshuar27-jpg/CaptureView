#pragma once

#include <CaptureView/Platform/Window.hpp>
#include <CaptureView/Rendering/Renderer.hpp>

namespace CaptureView::Core
{
    class Application
    {
    public:
        Application() = default;
        ~Application() = default;

        bool Initialize();
        int Run();
        void Shutdown();

    private:
        Platform::Window m_Window;
        Rendering::Renderer m_Renderer;
    };
}
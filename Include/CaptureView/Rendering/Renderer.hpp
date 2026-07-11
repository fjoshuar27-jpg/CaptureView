#pragma once

namespace CaptureView::Rendering
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        bool Initialize();

        void BeginFrame();

        void EndFrame();

        void Shutdown();

    private:
        bool m_Initialized = false;
    };
}
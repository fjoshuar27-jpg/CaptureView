#pragma once

#include <CaptureView/Graphics/GraphicsDevice.hpp>

namespace CaptureView::Rendering
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        bool Initialize(void* windowHandle);

        void BeginFrame();

        void EndFrame();

        void Shutdown();

    private:
        Graphics::GraphicsDevice m_GraphicsDevice;
        bool m_Initialized = false;
    };
}
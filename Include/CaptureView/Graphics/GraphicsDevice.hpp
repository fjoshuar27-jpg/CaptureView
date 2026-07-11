#pragma once

namespace CaptureView::Graphics
{
    class GraphicsDevice
    {
    public:
        GraphicsDevice() = default;
        ~GraphicsDevice() = default;

        bool Initialize();
        void BeginFrame();
        void EndFrame();
        void Shutdown();

    private:
        bool m_Initialized = false;
    };
}
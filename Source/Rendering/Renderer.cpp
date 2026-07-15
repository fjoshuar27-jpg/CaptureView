#include <CaptureView/Rendering/Renderer.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Rendering
{

    bool Renderer::Initialize(void* windowHandle)
    {
        CaptureView::Core::Logger::Info("Renderer: Initializing...");

        if (!m_GraphicsDevice.Initialize(windowHandle))
        {
            CaptureView::Core::Logger::Error("Renderer: Failed to initialize GraphicsDevice.");
            return false;
        }

        m_Initialized = true;

        CaptureView::Core::Logger::Info("Renderer: Ready.");

        return true;
    }

    void Renderer::BeginFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        m_GraphicsDevice.BeginFrame();
    }

    void Renderer::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        m_GraphicsDevice.EndFrame();
    }

    void Renderer::Shutdown()
    {
        if (!m_Initialized)
        {
            return;
        }

        m_GraphicsDevice.Shutdown();

        m_Initialized = false;

        CaptureView::Core::Logger::Info("Renderer: Shutdown.");
    }

} // namespace CaptureView::Rendering
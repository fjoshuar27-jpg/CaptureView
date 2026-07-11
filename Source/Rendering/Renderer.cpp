#include <CaptureView/Rendering/Renderer.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Rendering
{

    bool Renderer::Initialize()
    {
        CaptureView::Core::Logger::Info("Renderer: Initializing...");

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

        // Preparación del frame.
    }

    void Renderer::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Presentación del frame.
    }
    void Renderer::Shutdown()
    {
        if (!m_Initialized)
        {
            return;
        }

        CaptureView::Core::Logger::Info("Renderer: Shutdown.");

        m_Initialized = false;
    }

} // namespace CaptureView::Rendering
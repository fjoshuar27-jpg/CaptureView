#include <CaptureView/Graphics/GraphicsDevice.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Graphics
{

    bool GraphicsDevice::Initialize()
    {
        CaptureView::Core::Logger::Info("GraphicsDevice: Initializing...");

        m_Initialized = true;

        CaptureView::Core::Logger::Info("GraphicsDevice: Ready.");

        return true;
    }

    void GraphicsDevice::BeginFrame()
    {
        if (!m_Initialized)
        {
            return;
        }
    }

    void GraphicsDevice::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }
    }

    void GraphicsDevice::Shutdown()
    {
        if (!m_Initialized)
        {
            return;
        }

        CaptureView::Core::Logger::Info("GraphicsDevice: Shutdown.");

        m_Initialized = false;
    }

} // namespace CaptureView::Graphics
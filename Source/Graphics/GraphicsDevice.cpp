#include <CaptureView/Graphics/GraphicsDevice.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Graphics
{

    bool GraphicsDevice::Initialize(void* windowHandle)
    {
        (void)windowHandle;

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

        // Aquí irá el renderizado más adelante.
    }

    void GraphicsDevice::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Aquí presentaremos el frame más adelante.
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
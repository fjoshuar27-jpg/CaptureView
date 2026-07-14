#include <CaptureView/Graphics/GraphicsDevice.hpp>
#include <CaptureView/Core/Logger.hpp>

#include <d3d11.h>

#pragma comment(lib, "d3d11.lib")

namespace CaptureView::Graphics
{

    bool GraphicsDevice::Initialize(void* windowHandle)
    {
        CaptureView::Core::Logger::Info("GraphicsDevice: Initializing...");

        // Todavía no utilizamos la ventana.
        (void)windowHandle;

        D3D_FEATURE_LEVEL featureLevel{};

        HRESULT result = D3D11CreateDevice(
            nullptr,                    // Adaptador (GPU principal)
            D3D_DRIVER_TYPE_HARDWARE,   // Usar aceleración por hardware
            nullptr,                    // No usar módulo de software
            0,                          // Flags
            nullptr,                    // Feature levels soportados
            0,                          // Número de feature levels
            D3D11_SDK_VERSION,
            &m_Device,
            &featureLevel,
            &m_Context);

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error("GraphicsDevice: Failed to create Direct3D device.");
            return false;
        }

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

        if (m_Context != nullptr)
        {
            m_Context->Release();
            m_Context = nullptr;
        }

        if (m_Device != nullptr)
        {
            m_Device->Release();
            m_Device = nullptr;
        }

        CaptureView::Core::Logger::Info("GraphicsDevice: Shutdown.");

        m_Initialized = false;
    }

} // namespace CaptureView::Graphics
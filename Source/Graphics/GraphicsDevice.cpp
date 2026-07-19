#include <CaptureView/Graphics/GraphicsDevice.hpp>
#include <CaptureView/Core/Logger.hpp>

#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")

namespace CaptureView::Graphics
{

    bool GraphicsDevice::Initialize(void* windowHandle)
    {
        CaptureView::Core::Logger::Info("GraphicsDevice: Initializing...");

        if (!CreateDevice())
        {
            return false;
        }

        // Aún no implementadas
        // if (!CreateSwapChain(windowHandle))
        // {
        //     ReleaseDevice();
        //     return false;
        // }

        // if (!CreateRenderTarget())
        // {
        //     ReleaseSwapChain();
        //     ReleaseDevice();
        //     return false;
        // }

        m_Initialized = true;

        CaptureView::Core::Logger::Info("GraphicsDevice: Ready.");

        return true;
    }

    bool GraphicsDevice::CreateDevice()
    {
        HRESULT result = D3D11CreateDevice(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            0,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &m_Device,
            nullptr,
            &m_Context);

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error(
                "GraphicsDevice: Failed to create Direct3D Device.");

            return false;
        }

        CaptureView::Core::Logger::Info(
            "GraphicsDevice: Direct3D Device created.");

        return true;
    }

    bool GraphicsDevice::CreateSwapChain(void* windowHandle)
    {
        (void)windowHandle;

        // Build 0006
        return true;
    }

    bool GraphicsDevice::CreateRenderTarget()
    {
        // Build 0006
        return true;
    }

    void GraphicsDevice::BeginFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Build 0006
    }

    void GraphicsDevice::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Build 0006
    }

    void GraphicsDevice::ReleaseRenderTarget()
    {
        // Build 0006
    }

    void GraphicsDevice::ReleaseSwapChain()
    {
        // Build 0006
    }

    void GraphicsDevice::ReleaseDevice()
    {
        if (m_Context)
        {
            m_Context->Release();
            m_Context = nullptr;
        }

        if (m_Device)
        {
            m_Device->Release();
            m_Device = nullptr;
        }
    }

    void GraphicsDevice::Shutdown()
    {
        if (!m_Initialized)
        {
            return;
        }

        CaptureView::Core::Logger::Info("GraphicsDevice: Shutdown.");

        ReleaseRenderTarget();
        ReleaseSwapChain();
        ReleaseDevice();

        m_Initialized = false;
    }

} // namespace CaptureView::Graphics
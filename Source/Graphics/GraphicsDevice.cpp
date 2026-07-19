#include <CaptureView/Graphics/GraphicsDevice.hpp>
#include <CaptureView/Core/Logger.hpp>

#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")

namespace
{
    bool GetFactory(ID3D11Device* device, IDXGIFactory** factory)
    {
        IDXGIDevice* dxgiDevice = nullptr;
        IDXGIAdapter* adapter = nullptr;

        HRESULT result = device->QueryInterface(
            __uuidof(IDXGIDevice),
            reinterpret_cast<void**>(&dxgiDevice));

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error(
                "GraphicsDevice: Failed to query IDXGIDevice.");
            return false;
        }

        result = dxgiDevice->GetAdapter(&adapter);

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error(
                "GraphicsDevice: Failed to acquire DXGI Adapter.");

            dxgiDevice->Release();
            return false;
        }

        result = adapter->GetParent(
            __uuidof(IDXGIFactory),
            reinterpret_cast<void**>(factory));

        adapter->Release();
        dxgiDevice->Release();

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error(
                "GraphicsDevice: Failed to acquire DXGI Factory.");

            return false;
        }

        return true;
    }
}

namespace CaptureView::Graphics
{

    bool GraphicsDevice::Initialize(void* windowHandle)
    {
        CaptureView::Core::Logger::Info("GraphicsDevice: Initializing...");

        if (!CreateDevice())
        {
            return false;
        }

        if (!CreateSwapChain(windowHandle))
        {
            ReleaseDevice();
            return false;
        }

        // Próximo paso del Build 0006
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
        IDXGIFactory* factory = nullptr;

        if (!GetFactory(m_Device, &factory))
        {
            return false;
        }

        DXGI_SWAP_CHAIN_DESC swapChainDesc{};

        swapChainDesc.BufferDesc.Width = 0;
        swapChainDesc.BufferDesc.Height = 0;
        swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
        swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
        swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

        swapChainDesc.SampleDesc.Count = 1;
        swapChainDesc.SampleDesc.Quality = 0;

        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.BufferCount = 2;

        swapChainDesc.OutputWindow = reinterpret_cast<HWND>(windowHandle);

        swapChainDesc.Windowed = TRUE;

        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        swapChainDesc.Flags = 0;

        HRESULT result = factory->CreateSwapChain(
            m_Device,
            &swapChainDesc,
            &m_SwapChain);

        factory->Release();

        if (FAILED(result))
        {
            CaptureView::Core::Logger::Error(
                "GraphicsDevice: Failed to create Swap Chain.");

            return false;
        }

        CaptureView::Core::Logger::Info(
            "GraphicsDevice: Swap Chain created.");

        return true;
    }

    bool GraphicsDevice::CreateRenderTarget()
    {
        // Próximo paso
        return true;
    }

    void GraphicsDevice::BeginFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Próximo paso
    }

    void GraphicsDevice::EndFrame()
    {
        if (!m_Initialized)
        {
            return;
        }

        // Próximo paso
    }

    void GraphicsDevice::ReleaseRenderTarget()
    {
        if (m_RenderTargetView)
        {
            m_RenderTargetView->Release();
            m_RenderTargetView = nullptr;
        }
    }

    void GraphicsDevice::ReleaseSwapChain()
    {
        if (m_SwapChain)
        {
            m_SwapChain->Release();
            m_SwapChain = nullptr;
        }
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

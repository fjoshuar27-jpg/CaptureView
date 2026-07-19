#pragma once

struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;
struct ID3D11RenderTargetView;

namespace CaptureView::Graphics
{
    class GraphicsDevice
    {
    public:
        GraphicsDevice() = default;
        ~GraphicsDevice() = default;

        bool Initialize(void* windowHandle);

        void BeginFrame();

        void EndFrame();

        void Shutdown();

    private:

        bool CreateDevice();

        bool CreateSwapChain(void* windowHandle);

        bool CreateRenderTarget();

        void ReleaseRenderTarget();

        void ReleaseSwapChain();

        void ReleaseDevice();

        bool m_Initialized = false;

        ID3D11Device* m_Device = nullptr;
        ID3D11DeviceContext* m_Context = nullptr;

        IDXGISwapChain* m_SwapChain = nullptr;
        ID3D11RenderTargetView* m_RenderTargetView = nullptr;
    };
}
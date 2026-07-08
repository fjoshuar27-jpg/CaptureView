#include <CaptureView/Platform/Window.hpp>
#include <CaptureView/Core/Logger.hpp>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


namespace
{
    constexpr wchar_t kWindowClassName[] = L"CaptureViewWindow";

    LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam)
    {
        switch (message)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
}

namespace CaptureView::Platform
{

    bool Window::Create(std::wstring_view title, int width, int height)
    {
        CaptureView::Core::Logger::Info("Creating window...");
        CaptureView::Core::Logger::Error("CreateWindowExW failed.");
        CaptureView::Core::Logger::Info("Window created successfully.");

        HINSTANCE instance = GetModuleHandleW(nullptr);

        WNDCLASSW windowClass{};
        windowClass.lpfnWndProc = WindowProc;
        windowClass.hInstance = instance;
        windowClass.lpszClassName = kWindowClassName;
        windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);

        RegisterClassW(&windowClass);

        HWND hwnd = CreateWindowExW(
            0,
            kWindowClassName,
            title.data(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            width,
            height,
            nullptr,
            nullptr,
            instance,
            nullptr);

        if (hwnd == nullptr)
        {
            CaptureView::Core::Logger::Error("CreateWindowExW failed.");
            return false;
        }

        m_Handle = hwnd;
        m_IsOpen = true;

        CaptureView::Core::Logger::Info("Window created successfully.");

        return true;
    }

    bool Window::Show()
    {
        if (m_Handle == nullptr)
        {
            return false;
        }

        HWND hwnd = reinterpret_cast<HWND>(m_Handle);

        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);

        return true;
    }

    bool Window::ProcessEvents()
    {
        MSG message{};

        while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT)
            {
                m_IsOpen = false;
                break;
            }

            TranslateMessage(&message);
            DispatchMessageW(&message);
        }

        return m_IsOpen;
    }

    void Window::Destroy()
    {
        if (m_Handle != nullptr)
        {
            DestroyWindow(reinterpret_cast<HWND>(m_Handle));
            m_Handle = nullptr;
        }

        m_IsOpen = false;
    }

} // namespace CaptureView::Platform
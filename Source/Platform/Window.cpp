#include <CaptureView/Platform/Window.hpp>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
}

namespace CaptureView::Platform
{
    bool Window::Create(std::string_view title, int width, int height)
    {
        HINSTANCE instance = GetModuleHandle(nullptr);

        WNDCLASS wc{};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = instance;
        wc.lpszClassName = "CaptureViewWindow";
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

        if (!RegisterClass(&wc))
        {
            return false;
        }

        HWND hwnd = CreateWindow(
            "CaptureViewWindow",
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
            return false;
        }

        m_Handle = hwnd;

        return true;
    }

    bool Window::Show()
    {
        return true;
    }

    bool Window::ProcessEvents()
    {
        return true;
    }

    void Window::Destroy()
    {
    }
}
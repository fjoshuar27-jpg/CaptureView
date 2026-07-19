#pragma once

#include <string_view>

namespace CaptureView::Platform
{
    class Window
    {
    public:
        Window() = default;
        ~Window() = default;

        bool Create(std::wstring_view title, int width, int height);
        bool Show();
        bool ProcessEvents();
        void Destroy();

        void* GetNativeHandle() const;

        int GetWidth() const;
        int GetHeight() const;

    private:
        void* m_Handle = nullptr;
        bool m_IsOpen = false;

        int m_Width = 0;
        int m_Height = 0;
    };
}
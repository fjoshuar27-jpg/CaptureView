#pragma once

#include <string_view>

namespace CaptureView::Platform
{
    class Window
    {
    public:
        Window() = default;
        ~Window() = default;

        bool Create(std::string_view title,
            int width,
            int height);

        bool Show();

        bool ProcessEvents();

        void Destroy();

    private:
        void* m_Handle = nullptr;
    };
}
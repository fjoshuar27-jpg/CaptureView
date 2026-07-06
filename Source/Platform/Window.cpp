#include <CaptureView/Platform/Window.hpp>

namespace CaptureView::Platform
{
    bool Window::Create(std::string_view, int, int)
    {
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
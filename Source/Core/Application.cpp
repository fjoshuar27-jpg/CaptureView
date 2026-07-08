#include <CaptureView/Core/Application.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Core
{

    bool Application::Initialize()
    {
        Logger::Info("CaptureView 0.1.0");
        Logger::Info("Build 0003 - First Window");
        Logger::Info("Initializing...");

        if (!m_Window.Create(L"CaptureView", 1280, 720))
        {
            Logger::Error("Failed to create main window.");
            return false;
        }

        if (!m_Window.Show())
        {
            Logger::Error("Failed to show main window.");
            return false;
        }

        return true;
    }

    int Application::Run()
    {
        Logger::Info("Application is running.");

        while (m_Window.ProcessEvents())
        {
            // Aquí vivirá el renderizado.
        }

        return 0;
    }

    void Application::Shutdown()
    {
        m_Window.Destroy();

        Logger::Info("Shutdown complete.");
    }

} // namespace CaptureView::Core
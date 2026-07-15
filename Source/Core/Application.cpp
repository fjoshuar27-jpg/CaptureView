#include <CaptureView/Core/Application.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Core
{

    bool Application::Initialize()
    {
        Logger::Info("CaptureView 0.1.0");
        Logger::Info("Build 0004 - Rendering Foundation");
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

        if (!m_Renderer.Initialize(m_Window.GetNativeHandle()))
        {
            Logger::Error("Failed to initialize renderer.");
            return false;
        }

        return true;
    }

    int Application::Run()
    {
        Logger::Info("Application is running.");

        while (m_Window.ProcessEvents())
        {
            m_Renderer.BeginFrame();

            // Aquí vivirá el renderizado.

            m_Renderer.EndFrame();
        }

        return 0;
    }

    void Application::Shutdown()
    {
        m_Renderer.Shutdown();

        m_Window.Destroy();

        Logger::Info("Shutdown complete.");
    }

} // namespace CaptureView::Core
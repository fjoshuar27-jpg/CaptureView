#include <CaptureView/Core/Application.hpp>
#include <CaptureView/Core/Logger.hpp>

namespace CaptureView::Core
{

    bool Application::Initialize()
    {
        Logger::Info("CaptureView 0.1.0");
        Logger::Info("Build 0002 - Heartbeat");
        Logger::Info("Initializing...");

        return true;
    }

    int Application::Run()
    {
        Logger::Info("Application is running.");

        return 0;
    }

    void Application::Shutdown()
    {
        Logger::Info("Shutdown complete.");
    }

}
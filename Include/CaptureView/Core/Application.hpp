#pragma once

namespace CaptureView::Core
{
    class Application
    {
    public:
        Application() = default;
        ~Application() = default;

        bool Initialize();
        int Run();
        void Shutdown();
    };
}
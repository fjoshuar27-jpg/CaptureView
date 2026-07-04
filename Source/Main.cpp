#include <CaptureView/Core/Application.hpp>

int main()
{
    CaptureView::Core::Application application;

    if (!application.Initialize())
    {
        return -1;
    }

    const int result = application.Run();

    application.Shutdown();

    return result;
}
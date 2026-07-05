#include <CaptureView/Core/Logger.hpp>

#include <iostream>

namespace CaptureView::Core
{
    void Logger::Info(std::string_view message)
    {
        Write(LogLevel::Info, message);
    }

    void Logger::Warning(std::string_view message)
    {
        Write(LogLevel::Warning, message);
    }

    void Logger::Error(std::string_view message)
    {
        Write(LogLevel::Error, message);
    }

    void Logger::Write(LogLevel level, std::string_view message)
    {
        switch (level)
        {
        case LogLevel::Info:
            std::cout << "[INFO] " << message << '\n';
            break;

        case LogLevel::Warning:
            std::cout << "[WARNING] " << message << '\n';
            break;

        case LogLevel::Error:
            std::cout << "[ERROR] " << message << '\n';
            break;
        }
    }
}
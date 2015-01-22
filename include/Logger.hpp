#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

/// \brief A logger class made as Singleton. Prints all logs into a single log file. Each program run will clear log file.

//Macro so that logging is easier

#define LOG_STRING Logger::Get()->Log

namespace Taverner
{
    class Logger
    {
    protected:
        Logger();
        std::ofstream log;
        static Logger* m_instance;
    public:
        ~Logger();

        static Logger* Get();
        void Log(std::string logText);
    };
}

#endif //LOGGER_HPP

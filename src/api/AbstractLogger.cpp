#include "AbstractLogger.h"

AbstractLogger::AbstractLogger() : level(Log_Level_Debug), stream(nullptr)
{
    // ctor
}

AbstractLogger::AbstractLogger(std::ostream* str) : level(Log_Level_Debug), stream(str)
{
    // ctor
}

AbstractLogger::~AbstractLogger()
{
    // dtor
}

void AbstractLogger::log(const std::string text)
{
    log(level, text);
}

void AbstractLogger::set_log_level(const Log_Level lvl)
{
    level = lvl;
}

AbstractLogger::Log_Level_Set AbstractLogger::get_level_set() const
{
    return AbstractLogger::Log_Level_Set {
        Log_Level_Debug,
        Log_Level_Info,
        Log_Level_Warning,
        Log_Level_Error
    };
}

template <class T>
std::ostream& AbstractLogger::operator<<(T& data)
{
    std::ostream* tmp = stream ? stream : &std::cout;

    (*tmp) << get_log_line_header() << data;

    return *tmp;
}

void AbstractLogger::set_output_stream(std::ostream& str)
{
    stream = &str;
}

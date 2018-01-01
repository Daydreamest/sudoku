#include "AbstractLogger.h"

AbstractLogger::AbstractLogger() : level(Log_Level_Debug)
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

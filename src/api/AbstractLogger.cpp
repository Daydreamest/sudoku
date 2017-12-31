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

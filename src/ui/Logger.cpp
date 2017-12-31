#include "Logger.h"

#include <iostream>

Logger::Logger() : level_to_string_map(create_map())
{
    // ctor
}

Logger::~Logger()
{
    // dtor
}

Logger::handle_type Logger::create()
{
    return handle_type(new Logger);
}

void Logger::log(const Log_Level lvl, const std::string text)
{
    std::cout << log_to_str(lvl) << text << std::endl;
}

const std::string Logger::log_to_str(const Log_Level lvl)
{
    auto iter = level_to_string_map.find(lvl);
    if (iter != level_to_string_map.end()) {
        return iter->second;
    }

    return "    ";
}

const Logger::LevelStringMap Logger::create_map() const
{
    return std::map<Log_Level, std::string> {
        {Log_Level_Debug, "DBG "},
        {Log_Level_Info, "INF "},
        {Log_Level_Warning, "WAR "},
        {Log_Level_Error, "ERR "}
    };
}

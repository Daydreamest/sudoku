#include "Logger.h"

#include <iostream>

Logger::Logger(const Log_Level lvl, std::ostream& out) : level_to_string_map(create_map()), level(lvl), output(out)
{
    // ctor
}

Logger::~Logger()
{
    // dtor
}

void Logger::log(const Log_Level lvl, const std::string text)
{
    std::cout << level_to_str(lvl) << text << std::endl;
}

const std::string Logger::level_to_str(const Log_Level lvl) const
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

void Logger::log(const std::string text)
{
    log(level, text);
}

void Logger::set_log_level(const Log_Level lvl)
{
    level = lvl;
}

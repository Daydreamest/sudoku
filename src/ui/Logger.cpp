#include "Logger.h"

#include <iostream>

Logger::Logger(const Log_Level lvl, std::ostream& out) : level_to_string_map(create_map()), level(lvl), output(out)
{
    // ctor
    null_buffer = std::make_unique<NullBuffer>();
    null_stream = std::make_unique<std::ostream>(null_buffer.get());
}

Logger::~Logger()
{
    // dtor
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

void Logger::set_log_level(const Log_Level lvl)
{
    level = lvl;
}

std::ostream& Logger::operator()(const Log_Level lvl)
{
    if (lvl < level) {
        return *null_stream;
    }

    output << level_to_str(lvl);
    return output;
}

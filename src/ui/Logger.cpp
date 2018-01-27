#include "Logger.h"

#include <iostream>

namespace sudoku {
namespace ui {

Logger::Logger(const LogLevel lvl, std::ostream& out) : level_to_string_map(create_map()), level(lvl), output(out)
{
    // ctor
    null_buffer = std::make_unique<NullBuffer>();
    null_stream = std::make_unique<std::ostream>(null_buffer.get());
}

Logger::~Logger()
{
    // dtor
}

const std::string Logger::level_to_str(const LogLevel lvl) const
{
    auto iter = level_to_string_map.find(lvl);
    if (iter != level_to_string_map.end()) {
        return iter->second;
    }

    return "    ";
}

const Logger::LevelStringMap Logger::create_map() const
{
    return std::map<LogLevel, std::string> {
        {LogLevel_Debug, "DBG "},
        {LogLevel_Info, "INF "},
        {LogLevel_Warning, "WAR "},
        {LogLevel_Error, "ERR "}
    };
}

void Logger::set_log_level(const LogLevel lvl)
{
    level = lvl;
}

std::ostream& Logger::operator()(const LogLevel lvl)
{
    if (lvl < level) {
        return *null_stream;
    }

    output << level_to_str(lvl);
    return output;
}

} //namespace ui
} // namespace sudoku

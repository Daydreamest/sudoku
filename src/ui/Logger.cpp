#include "Logger.h"

#include <iostream>

//template<class T>
//std::ostream& operator<<(Logger& logger, T& data)
//{
//    std::cout << data;
//
//    return std::cout;
//}

//template<>
//std::ostream& operator<<(Logger& logger, Log_Level data)
//{
//    std::cout << logger.level_to_str(data);
//
//    return std::cout;
//}

Logger::Logger(const Log_Level lvl, std::ostream& out) : level_to_string_map(create_map()), level(lvl), output(out)
{
    // ctor
}

Logger::~Logger()
{
    // dtor
}

//Logger::handle_type Logger::create()
//{
//    auto result = handle_type(new Logger(Log_Level_Debug));
////    result->set_output_stream(std::cout);
//    return result;
//}

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

//std::string Logger::get_log_line_header() const
//{
//    return log_to_str(level);
//}

void Logger::log(const std::string text)
{
    log(level, text);
}

void Logger::set_log_level(const Log_Level lvl)
{
    level = lvl;
}

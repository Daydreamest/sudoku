#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <map>
#include <memory>
#include <sstream>

namespace sudoku {

enum LogLevel {
    LogLevel_Debug = 0,
    LogLevel_Info,
    LogLevel_Warning,
    LogLevel_Error,
    LogLevel_None
};

namespace ui {

class Logger
{
    public:
        Logger(const LogLevel lvl = LogLevel_None, std::ostream& out = std::cout);
        virtual ~Logger();

        void set_log_level(const LogLevel lvl);

        std::ostream& operator()(const LogLevel lvl);

    protected:

    private:
        using LevelStringMap = std::map<LogLevel, std::string>;

        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;

        const std::string level_to_str(const LogLevel lvl) const;

        LogLevel level;

        std::ostream& output;

        class NullBuffer : public std::streambuf
        {
            public:
                int overflow(int c) { return c; }
        };

        std::unique_ptr<NullBuffer> null_buffer;
        std::unique_ptr<std::ostream> null_stream;
};

} //namespace ui
} // namespace sudoku

#endif // LOGGER_H

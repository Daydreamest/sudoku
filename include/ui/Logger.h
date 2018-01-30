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
        // COnstructor
        Logger(const LogLevel lvl = LogLevel_None, std::ostream& out = std::cout);

        //Destructor
        virtual ~Logger();

        // Setter for the logging level
        void set_log_level(const LogLevel lvl);

        // Function opertator to create logging ostream
        std::ostream& operator()(const LogLevel lvl);

    protected:

    private:
        // Translation map type definition
        using LevelStringMap = std::map<LogLevel, std::string>;

        // Translation map of logging level to string
        const LevelStringMap level_to_string_map;

        // Translation map creator
        const LevelStringMap create_map() const;

        // Logging level to string translator
        const std::string level_to_str(const LogLevel lvl) const;

        // Logging level used as a threshold to output logs
        LogLevel level;

        // Output stream
        std::ostream& output;

        // Null buffer that ignores all data placed in it
        class NullBuffer : public std::streambuf
        {
            public:
                int overflow(int c) { return c; }
        };

        // Null buffer instance
        std::unique_ptr<NullBuffer> null_buffer;

        // Null stream that ignores all date written to it
        std::unique_ptr<std::ostream> null_stream;
};

} //namespace ui
} // namespace sudoku

#endif // LOGGER_H

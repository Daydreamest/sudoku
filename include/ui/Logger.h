#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <map>
#include <memory>
#include <sstream>

enum Log_Level {
    Log_Level_Debug = 0,
    Log_Level_Info,
    Log_Level_Warning,
    Log_Level_Error,
    Log_Level_None
};

class Logger
{
    public:
        Logger(const Log_Level lvl = Log_Level_None, std::ostream& out = std::cout);
        virtual ~Logger();

        void set_log_level(const Log_Level lvl);

        std::ostream& operator()(const Log_Level lvl);

    protected:

    private:
        using LevelStringMap = std::map<Log_Level, std::string>;

        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;

        const std::string level_to_str(const Log_Level lvl) const;

        Log_Level level;

        std::ostream& output;

        class NullBuffer : public std::streambuf
        {
            public:
                int overflow(int c) { return c; }
        };

        std::unique_ptr<NullBuffer> null_buffer;
        std::unique_ptr<std::ostream> null_stream;
};

#endif // LOGGER_H

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <map>
#include <memory>
#include <sstream>

enum Log_Level {
    Log_Level_Debug,
    Log_Level_Info,
    Log_Level_Warning,
    Log_Level_Error,
    Log_Level_None
};

class Logger
{
    public:
        //TODO remove
        using handle_type = std::shared_ptr<Logger>;

        virtual ~Logger();

        void set_log_level(const Log_Level lvl);

        Logger(const Log_Level lvl = Log_Level_None, std::ostream& out = std::cout);

        const std::string level_to_str(const Log_Level lvl) const;

        std::ostream& operator()(const Log_Level lvl);

    protected:

    private:
        using LevelStringMap = std::map<Log_Level, std::string>;


        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;

        Log_Level level;

        std::ostream& output;
};

#endif // LOGGER_H

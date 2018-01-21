#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <map>
#include <memory>

//#include <AbstractLogger.h>

enum Log_Level {
    Log_Level_Debug,
    Log_Level_Info,
    Log_Level_Warning,
    Log_Level_Error,
    Log_Level_None
};

class Logger// : public AbstractLogger
{
    public:

        //TODO remove
        using handle_type = std::shared_ptr<Logger>;

        virtual ~Logger();

        virtual void log(const Log_Level lvl, const std::string text);
        virtual void log(const std::string text) final;

        void set_log_level(const Log_Level lvl);

        Logger(const Log_Level lvl = Log_Level_None, std::ostream& out = std::cout);

    protected:

//        virtual std::string get_log_line_header() const override;

    private:
        using LevelStringMap = std::map<Log_Level, std::string>;

        const std::string level_to_str(const Log_Level lvl) const;

        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;

        Log_Level level;

        std::ostream& output;
};

template<typename T>
std::ostream& operator<<(Logger& logger, T& data)
{
        std::cout << data;

    return std::cout;
}

#endif // LOGGER_H

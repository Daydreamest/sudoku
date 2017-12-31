#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <memory>
#include <string>

enum Log_Level{
    Log_Level_Debug,
    Log_Level_Info,
    Log_Level_Warning,
    Log_Level_Error
};

class AbstractLogger {

    public:
        using handle_type = std::shared_ptr<AbstractLogger>;

        AbstractLogger();
        virtual ~AbstractLogger();

        virtual void log(const std::string text) final;

        virtual void log(const Log_Level lvl, const std::string text) = 0;

        void set_log_level(const Log_Level lvl);

    private:
        Log_Level level;
};

#endif // ABSTRACTLOGGER_H

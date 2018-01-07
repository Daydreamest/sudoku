#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

//#include <iostream>
#include <memory>
#include <set>
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
//        AbstractLogger(std::ostream* str);
        virtual ~AbstractLogger();

//        AbstractLogger(const AbstractLogger& abs);

        virtual void log(const std::string text) final;

        virtual void log(const Log_Level lvl, const std::string text) = 0;

//        void set_output_stream(std::ostream& str);

//        template<typename T>
//        std::ostream& operator<<(T& data);

        void set_log_level(const Log_Level lvl);

    protected:
//        using Log_Level_Set = std::set<Log_Level>;

//        Log_Level_Set get_level_set() const;

//        virtual std::string get_log_line_header() const = 0;

        Log_Level level;

    private:

//        AbstractLogger& operator=(const AbstractLogger&);
//        std::ostream* stream;
};

#endif // ABSTRACTLOGGER_H

#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <string>

#include <AbstractLogger.h>

class LoggerInterface
{
    public:
        LoggerInterface();
        virtual ~LoggerInterface();

        virtual void set_logger(const AbstractLogger::handle_type l);

        virtual void log(const std::string text);

    protected:
        AbstractLogger::handle_type logger;

    private:
};

#endif // LOGGERINTERFACE_H

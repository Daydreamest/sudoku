#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <iostream>
#include <string>

#include <AbstractLogger.h>

class LoggerInterface
{
    public:
        class StreamLogger {
            public:
                StreamLogger();
                virtual ~StreamLogger();

                AbstractLogger::handle_type logger;

                bool is_set() const;

                void operator()(const std::string text);
        };


    public:
        LoggerInterface();
        virtual ~LoggerInterface();

        virtual void set_logger(const AbstractLogger::handle_type l);

        StreamLogger log;

    protected:

    private:
};

template<typename T>
std::ostream& operator<<(LoggerInterface::StreamLogger& helper, T& data)
{
        std::cout << data;

    return std::cout;
}

#endif // LOGGERINTERFACE_H

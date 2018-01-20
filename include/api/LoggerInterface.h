#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <iostream>
#include <string>

#include <AbstractLogger.h>

class LoggerInterface
{
    public:
        class LogHelper {
            public:
                LogHelper();
                virtual ~LogHelper();

                AbstractLogger::handle_type logger;

//                template<typename T>
//                std::ostream& operator<<(T& data);

                bool is_set() const;
        };


    public:
        LoggerInterface();
        virtual ~LoggerInterface();

        virtual void set_logger(const AbstractLogger::handle_type l);

        virtual void log(const std::string text);

        LogHelper logger;

    protected:

    private:
};

template<typename T>
std::ostream& operator<<(LoggerInterface::LogHelper& helper, T& data)
{
        std::cout << data;

    return std::cout;
}

#endif // LOGGERINTERFACE_H

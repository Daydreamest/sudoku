#include "LoggerInterface.h"

LoggerInterface::LoggerInterface()
{
    //ctor
}

LoggerInterface::~LoggerInterface()
{
    //dtor
}

void LoggerInterface::set_logger(const AbstractLogger::handle_type l)
{
    logger.logger = l;
}

void LoggerInterface::log(const std::string text)
{
    if (logger.is_set()) {
        logger.logger->log(text);
    }
    // TODO warning if no logger available
}

//template <typename T>
//std::ostream& LoggerInterface::LogHelper::operator<<(T& data)
//{
//    if (is_set()) {
//        //TODO setup ostream accortdingly
//        std::cout << data;
//        return std::cout;
//    }
//
//
////    (*tmp) << get_log_line_header() << data;
//
//    return std::cout;
//}

bool LoggerInterface::LogHelper::is_set() const
{
    if (logger) {
        return true;
    }

    return false;
}

LoggerInterface::LogHelper::LogHelper() : logger(nullptr)
{

}

LoggerInterface::LogHelper::~LogHelper()
{

}

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
    log.logger = l;
}

bool LoggerInterface::StreamLogger::is_set() const
{
    if (logger) {
        return true;
    }

    return false;
}

LoggerInterface::StreamLogger::StreamLogger() : logger(nullptr)
{

}

LoggerInterface::StreamLogger::~StreamLogger()
{

}

void LoggerInterface::StreamLogger::operator()(const std::string text)
{
    if (is_set()) {
        logger->log(text);
    }
//    // TODO warning if no logger available
}

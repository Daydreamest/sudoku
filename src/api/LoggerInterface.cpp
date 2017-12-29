#include "LoggerInterface.h"

LoggerInterface::LoggerInterface() : logger(nullptr)
{
    //ctor
}

LoggerInterface::~LoggerInterface()
{
    //dtor
}

void LoggerInterface::set_logger(const AbstractLogger::handle_type l)
{
    logger = l;
}

void LoggerInterface::log(const std::string text)
{
    if (logger) {
        logger->log(text);
    }
    // TODO warning if no logger available
}

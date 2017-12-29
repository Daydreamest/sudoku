#include "Logger.h"

#include <iostream>

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}

Logger::handle_type Logger::create()
{
    return handle_type(new Logger);
}

void Logger::log(const std::string text)
{
    std::cout << "Log info: " << text << std::endl;
}

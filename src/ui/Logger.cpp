#include "Logger.h"

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

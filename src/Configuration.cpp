#include "Configuration.h"

#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

Configuration::Configuration()
{
    //ctor
}

Configuration::~Configuration()
{
    //dtor
}

void Configuration::set_log_level(const LogLevel ll)
{
    log_level = ll;
    log.set_log_level(ll);
}

void Configuration::set_verbosity(const bool v)
{
    verbosity = v;
}

const bool Configuration::is_verbose() const
{
    return verbosity;
}


} // namespace sudoku

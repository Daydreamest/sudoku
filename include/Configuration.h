#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <Logger.h>

namespace sudoku {

class Configuration
{
    public:
        Configuration();
        virtual ~Configuration();

        void set_log_level(const LogLevel);
        void set_verbosity(const bool v);

        const bool is_verbose() const;

    private:
        LogLevel log_level;
        bool verbosity;
};

} // namespace sudoku

#endif // CONFIGURATION_H

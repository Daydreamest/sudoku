#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <Logger.h>

namespace sudoku {

class Configuration
{
    public:
        // Constructor
        Configuration();

        // Destructor
        virtual ~Configuration();

        // Logging level setter
        void set_log_level(const LogLevel);

        // Verbosity setter
        void set_verbosity(const bool v);

        // Verbosity reader
        const bool is_verbose() const;

    private:
        // Current log level
        LogLevel log_level;

        // Current verbosity
        bool verbosity;
};

} // namespace sudoku

#endif // CONFIGURATION_H

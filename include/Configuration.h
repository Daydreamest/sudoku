#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

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

        // Set input file name
        void set_input_data(const std::string name);

        // Get input file name
        const std::string get_input_data() const;

    private:
        // Current log level
        LogLevel log_level;

        // Current verbosity
        bool verbosity;

        // Name of the file with input data
        std::string input_file;
};

} // namespace sudoku

#endif // CONFIGURATION_H

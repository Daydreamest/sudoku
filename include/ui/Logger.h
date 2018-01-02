#ifndef LOGGER_H
#define LOGGER_H

#include <map>
#include <memory>

#include <AbstractLogger.h>

class Logger : public AbstractLogger
{
    public:

        using handle_type = std::shared_ptr<Logger>;

        static handle_type create();

        virtual ~Logger();

        virtual void log(const Log_Level lvl, const std::string text) override;

    protected:
        Logger();

        virtual std::string get_log_line_header() const override;

    private:
        using LevelStringMap = std::map<Log_Level, std::string>;

        const std::string log_to_str(const Log_Level lvl) const;

        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;
};

#endif // LOGGER_H

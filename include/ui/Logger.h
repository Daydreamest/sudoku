#ifndef LOGGER_H
#define LOGGER_H

#include <memory>

#include <AbstractLogger.h>

class Logger : public AbstractLogger
{
    public:

        using handle_type = std::shared_ptr<Logger>;

        static handle_type create();

        virtual ~Logger();

        virtual void log(const std::string text) override;

    protected:
        Logger();

    private:
};

#endif // LOGGER_H

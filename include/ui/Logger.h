#ifndef LOGGER_H
#define LOGGER_H

#include <memory>

class Logger
{
    public:

        using handle_type = std::shared_ptr<Logger>;

        static handle_type create();

        virtual ~Logger();

    protected:
        Logger();

    private:
};

#endif // LOGGER_H

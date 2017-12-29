#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <memory>

class AbstractLogger {

    public:

        using handle_type = std::shared_ptr<AbstractLogger>;

        AbstractLogger() {};
        virtual ~AbstractLogger() {};

        virtual void log(const std::string text) = 0;
};

#endif // ABSTRACTLOGGER_H

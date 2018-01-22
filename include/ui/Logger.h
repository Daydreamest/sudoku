#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <map>
#include <memory>
#include <sstream>

//#include <AbstractLogger.h>

enum Log_Level {
    Log_Level_Debug,
    Log_Level_Info,
    Log_Level_Warning,
    Log_Level_Error,
    Log_Level_None
};

class Logger// : public AbstractLogger
{
    public:

//        class LoggerStreamer
//        {
//            public:
//                std::stringstream stream;
//                std::ostream& outstream;
//
//                LoggerStreamer(std::ostream& out) : outstream(out) {}
//                ~LoggerStreamer() {
//                    stream << " Destroyer! " << std::endl;
//                    outstream << stream.rdbuf();
//                    outstream.flush();
//                }
//
//                template<typename T>
//                Logger::LoggerStreamer& operator<<(const T& data) {
//                    stream << data;
//                    return *this;
//                }
//        };

        //TODO remove
        using handle_type = std::shared_ptr<Logger>;

        virtual ~Logger();

        virtual void log(const Log_Level lvl, const std::string text);
        virtual void log(const std::string text) final;

        void set_log_level(const Log_Level lvl);

        Logger(const Log_Level lvl = Log_Level_None, std::ostream& out = std::cout);

        const std::string level_to_str(const Log_Level lvl) const;

        std::ostream& operator()(const Log_Level lvl){
            std::cout << level_to_str(lvl);
            return std::cout;
        }

    protected:

//        virtual std::string get_log_line_header() const override;

    private:
        using LevelStringMap = std::map<Log_Level, std::string>;


        const LevelStringMap level_to_string_map;
        const LevelStringMap create_map() const;

        Log_Level level;

        std::ostream& output;
};

//template<class T>
//std::ostream& operator<<(Logger& logger, T& data)
//{
//    std::cout << data;
//
//    return std::cout;
//}
//

//template<>
//std::ostream& operator<<(Logger& logger, Log_Level& data);


//template<typename T>
//Logger::LoggerStreamer&& operator<<(Logger& logger, T& data)
//{
//    Logger::LoggerStreamer streamer(std::cout);
//
//    streamer << "TEST " << data;
//
//    return std::move(streamer);
//}

#endif // LOGGER_H

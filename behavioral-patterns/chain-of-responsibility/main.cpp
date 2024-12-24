#include <iostream>
#include <memory>
#include <string>

// 抽象处理者类
class Logger
{
protected:
    std::shared_ptr<Logger> next; // 下一个处理者
    int level;                    // 当前处理者能处理的日志级别

public:
    explicit Logger(int logLevel)
        : level(logLevel)
        , next(nullptr)
    {
    }

    virtual ~Logger() = default;

    void setNext(std::shared_ptr<Logger> nextLogger) { next = nextLogger; }

    void logMessage(int logLevel, const std::string &message)
    {
        if (logLevel >= level) {
            write(message); // 当前处理者处理请求
        }
        if (next) {
            next->logMessage(logLevel, message); // 将请求传递给下一个处理者
        }
    }

    virtual void write(const std::string &message) = 0; // 具体处理逻辑（抽象方法）
};

// 具体处理者类：控制台日志
class ConsoleLogger : public Logger
{
public:
    explicit ConsoleLogger(int logLevel)
        : Logger(logLevel)
    {
    }

    void write(const std::string &message) override
    {
        std::cout << "[Console] " << message << std::endl;
    }
};

// 具体处理者类：文件日志
class FileLogger : public Logger
{
public:
    explicit FileLogger(int logLevel)
        : Logger(logLevel)
    {
    }

    void write(const std::string &message) override
    {
        std::cout << "[File] " << message << std::endl;
    }
};

// 具体处理者类：错误日志
class ErrorLogger : public Logger
{
public:
    explicit ErrorLogger(int logLevel)
        : Logger(logLevel)
    {
    }

    void write(const std::string &message) override
    {
        std::cout << "[Error] " << message << std::endl;
    }
};

// 主函数
int main()
{
    // 创建责任链中的处理者
    auto errorLogger = std::make_shared<ErrorLogger>(3);
    auto fileLogger = std::make_shared<FileLogger>(2);
    auto consoleLogger = std::make_shared<ConsoleLogger>(1);

    // 设置责任链
    consoleLogger->setNext(fileLogger);
    fileLogger->setNext(errorLogger);

    // 测试责任链
    std::cout << "Logging INFO message:" << std::endl;
    consoleLogger->logMessage(1, "This is an INFO message.");

    std::cout << "\nLogging WARNING message:" << std::endl;
    consoleLogger->logMessage(2, "This is a WARNING message.");

    std::cout << "\nLogging ERROR message:" << std::endl;
    consoleLogger->logMessage(3, "This is an ERROR message.");

    return 0;
}
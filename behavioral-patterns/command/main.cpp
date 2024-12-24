#include <iostream>
#include <memory>
#include <vector>

// 命令接口
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0; // 执行命令
    virtual void undo() = 0;    // 撤销命令
};

// 电灯接收者类
class Light
{
public:
    void turnOn() { std::cout << "Light is ON" << std::endl; }

    void turnOff() { std::cout << "Light is OFF" << std::endl; }
};

// 电灯打开命令
class LightOnCommand : public Command
{
private:
    Light &light;

public:
    explicit LightOnCommand(Light &l)
        : light(l)
    {
    }

    void execute() override { light.turnOn(); }

    void undo() override { light.turnOff(); }
};

// 电灯关闭命令
class LightOffCommand : public Command
{
private:
    Light &light;

public:
    explicit LightOffCommand(Light &l)
        : light(l)
    {
    }

    void execute() override { light.turnOff(); }

    void undo() override { light.turnOn(); }
};

// 风扇接收者类
class Fan
{
public:
    void turnOn() { std::cout << "Fan is ON" << std::endl; }

    void turnOff() { std::cout << "Fan is OFF" << std::endl; }
};

// 风扇打开命令
class FanOnCommand : public Command
{
private:
    Fan &fan;

public:
    explicit FanOnCommand(Fan &f)
        : fan(f)
    {
    }

    void execute() override { fan.turnOn(); }

    void undo() override { fan.turnOff(); }
};

// 风扇关闭命令
class FanOffCommand : public Command
{
private:
    Fan &fan;

public:
    explicit FanOffCommand(Fan &f)
        : fan(f)
    {
    }

    void execute() override { fan.turnOff(); }

    void undo() override { fan.turnOn(); }
};

// 调用者类
class RemoteControl
{
private:
    std::vector<std::shared_ptr<Command>> commandHistory;

public:
    void executeCommand(const std::shared_ptr<Command> &command)
    {
        command->execute();
        commandHistory.push_back(command); // 保存历史以便撤销
    }

    void undoLastCommand()
    {
        if (!commandHistory.empty()) {
            commandHistory.back()->undo();
            commandHistory.pop_back();
        } else {
            std::cout << "No commands to undo" << std::endl;
        }
    }
};

// 主函数
int main()
{
    // 创建接收者
    Light livingRoomLight;
    Fan ceilingFan;

    // 创建命令
    auto lightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto lightOff = std::make_shared<LightOffCommand>(livingRoomLight);
    auto fanOn = std::make_shared<FanOnCommand>(ceilingFan);
    auto fanOff = std::make_shared<FanOffCommand>(ceilingFan);

    // 创建调用者
    RemoteControl remote;

    // 执行命令
    std::cout << "Executing commands:" << std::endl;
    remote.executeCommand(lightOn);
    remote.executeCommand(fanOn);

    // 撤销命令
    std::cout << "\nUndoing last commands:" << std::endl;
    remote.undoLastCommand();
    remote.undoLastCommand();

    // 尝试撤销多余的命令
    std::cout << "\nUndoing with no commands left:" << std::endl;
    remote.undoLastCommand();

    return 0;
}
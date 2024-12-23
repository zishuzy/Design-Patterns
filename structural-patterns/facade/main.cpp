#include <iostream>

// 子系统1：电视
class Television
{
public:
    void on() { std::cout << "Television is ON." << std::endl; }
    void off() { std::cout << "Television is OFF." << std::endl; }
};

// 子系统2：音响
class SoundSystem
{
public:
    void on() { std::cout << "SoundSystem is ON." << std::endl; }
    void setVolume(int volume)
    {
        std::cout << "SoundSystem volume set to " << volume << "." << std::endl;
    }
    void off() { std::cout << "SoundSystem is OFF." << std::endl; }
};

// 子系统3：投影仪
class Projector
{
public:
    void on() { std::cout << "Projector is ON." << std::endl; }
    void setInput(const std::string &input)
    {
        std::cout << "Projector input set to " << input << "." << std::endl;
    }
    void off() { std::cout << "Projector is OFF." << std::endl; }
};

// 外观类：家庭影院
class HomeTheaterFacade
{
private:
    Television tv;
    SoundSystem soundSystem;
    Projector projector;

public:
    void watchMovie()
    {
        std::cout << "Setting up to watch a movie..." << std::endl;
        tv.on();
        soundSystem.on();
        soundSystem.setVolume(50);
        projector.on();
        projector.setInput("HDMI");
        std::cout << "Movie is ready to play!" << std::endl;
    }

    void endMovie()
    {
        std::cout << "Shutting down movie system..." << std::endl;
        projector.off();
        soundSystem.off();
        tv.off();
        std::cout << "Movie system is off." << std::endl;
    }
};

// 主函数
int main()
{
    HomeTheaterFacade homeTheater;

    // 一键启动看电影
    homeTheater.watchMovie();

    std::cout << std::endl;

    // 一键关闭系统
    homeTheater.endMovie();

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 抽象观察者接口
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const std::string &weather) = 0;
};

// 被观察者类
class WeatherStation
{
private:
    std::vector<std::shared_ptr<Observer>> observers;
    std::string weather;

public:
    void addObserver(const std::shared_ptr<Observer> &observer) { observers.push_back(observer); }

    void removeObserver(const std::shared_ptr<Observer> &observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setWeather(const std::string &newWeather)
    {
        weather = newWeather;
        notifyObservers();
    }

    void notifyObservers()
    {
        for (const auto &observer : observers) {
            observer->update(weather);
        }
    }
};

// 具体观察者类：手机
class PhoneDisplay : public Observer
{
private:
    std::string name;

public:
    explicit PhoneDisplay(const std::string &n)
        : name(n)
    {
    }
    void update(const std::string &weather) override
    {
        std::cout << "[" << name << "] Phone Display: Weather updated to " << weather << std::endl;
    }
};

// 具体观察者类：平板
class TabletDisplay : public Observer
{
private:
    std::string name;

public:
    explicit TabletDisplay(const std::string &n)
        : name(n)
    {
    }
    void update(const std::string &weather) override
    {
        std::cout << "[" << name << "] Tablet Display: Weather updated to " << weather << std::endl;
    }
};

int main()
{
    // 创建被观察者
    WeatherStation weatherStation;

    // 创建观察者
    auto phoneDisplay1 = std::make_shared<PhoneDisplay>("Alice");
    auto phoneDisplay2 = std::make_shared<PhoneDisplay>("Bob");
    auto tabletDisplay = std::make_shared<TabletDisplay>("Charlie");

    // 添加观察者
    weatherStation.addObserver(phoneDisplay1);
    weatherStation.addObserver(phoneDisplay2);
    weatherStation.addObserver(tabletDisplay);

    // 更新天气
    std::cout << "Weather changes to Sunny:" << std::endl;
    weatherStation.setWeather("Sunny");

    // 移除一个观察者
    weatherStation.removeObserver(phoneDisplay2);

    // 再次更新天气
    std::cout << "\nWeather changes to Rainy:" << std::endl;
    weatherStation.setWeather("Rainy");

    return 0;
}
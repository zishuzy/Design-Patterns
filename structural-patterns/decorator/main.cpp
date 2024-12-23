#include <iostream>
#include <memory>
#include <string>

// 抽象基类 Component
class Beverage
{
public:
    virtual ~Beverage() = default;
    virtual std::string GetDescription() const = 0;
    virtual double Cost() const = 0;
};

// 具体组件 ConcreteComponent
class Coffee : public Beverage
{
public:
    std::string GetDescription() const override { return "Coffee"; }
    double Cost() const override
    {
        return 5.0; // 基础咖啡价格
    }
};

// 装饰器基类 Decorator
class CondimentDecorator : public Beverage
{
protected:
    std::shared_ptr<Beverage> beverage; // 被装饰的对象
public:
    explicit CondimentDecorator(std::shared_ptr<Beverage> bev)
        : beverage(std::move(bev))
    {
    }
};

// 具体装饰器 ConcreteDecorator1
class Milk : public CondimentDecorator
{
public:
    explicit Milk(std::shared_ptr<Beverage> bev)
        : CondimentDecorator(std::move(bev))
    {
    }

    std::string GetDescription() const override { return beverage->GetDescription() + ", Milk"; }
    double Cost() const override
    {
        return beverage->Cost() + 1.5; // 牛奶额外价格
    }
};

// 具体装饰器 ConcreteDecorator2
class Sugar : public CondimentDecorator
{
public:
    explicit Sugar(std::shared_ptr<Beverage> bev)
        : CondimentDecorator(std::move(bev))
    {
    }

    std::string GetDescription() const override { return beverage->GetDescription() + ", Sugar"; }
    double Cost() const override
    {
        return beverage->Cost() + 0.5; // 糖额外价格
    }
};

// 主函数
int main()
{
    // 创建基础饮料
    std::shared_ptr<Beverage> beverage = std::make_shared<Coffee>();

    // 添加装饰器
    beverage = std::make_shared<Milk>(beverage);  // 添加牛奶
    beverage = std::make_shared<Sugar>(beverage); // 添加糖

    // 输出最终饮料描述和价格
    std::cout << "Beverage: " << beverage->GetDescription() << std::endl;
    std::cout << "Cost: $" << beverage->Cost() << std::endl;

    return 0;
}
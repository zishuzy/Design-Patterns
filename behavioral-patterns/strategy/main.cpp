#include <iostream>
#include <memory>
#include <string>

// 抽象策略类
class PaymentStrategy
{
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(int amount) = 0;
};

// 具体策略类：信用卡支付
class CreditCardPayment : public PaymentStrategy
{
private:
    std::string name;
    std::string cardNumber;

public:
    CreditCardPayment(const std::string &name, const std::string &cardNumber)
        : name(name)
        , cardNumber(cardNumber)
    {
    }

    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using Credit Card (" << cardNumber << ")." << std::endl;
    }
};

// 具体策略类：PayPal 支付
class PayPalPayment : public PaymentStrategy
{
private:
    std::string email;

public:
    explicit PayPalPayment(const std::string &email)
        : email(email)
    {
    }

    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using PayPal (" << email << ")." << std::endl;
    }
};

// 具体策略类：比特币支付
class BitcoinPayment : public PaymentStrategy
{
private:
    std::string walletAddress;

public:
    explicit BitcoinPayment(const std::string &walletAddress)
        : walletAddress(walletAddress)
    {
    }

    void pay(int amount) override
    {
        std::cout << "Paid " << amount << " using Bitcoin (Wallet: " << walletAddress << ")."
                  << std::endl;
    }
};

// 环境类
class PaymentContext
{
private:
    std::shared_ptr<PaymentStrategy> strategy;

public:
    void setStrategy(const std::shared_ptr<PaymentStrategy> &newStrategy)
    {
        strategy = newStrategy;
    }

    void executePayment(int amount)
    {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cerr << "Payment strategy not set!" << std::endl;
        }
    }
};

int main()
{
    PaymentContext context;

    // 使用信用卡支付
    context.setStrategy(std::make_shared<CreditCardPayment>("John Doe", "1234-5678-9012-3456"));
    context.executePayment(100);

    // 切换到 PayPal 支付
    context.setStrategy(std::make_shared<PayPalPayment>("john.doe@example.com"));
    context.executePayment(200);

    // 切换到比特币支付
    context.setStrategy(std::make_shared<BitcoinPayment>("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"));
    context.executePayment(300);

    return 0;
}
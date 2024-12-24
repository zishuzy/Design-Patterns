#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// 抽象享元类 Flyweight
class GoPiece
{
public:
    virtual ~GoPiece() = default;

    // 显示棋子
    virtual void display(int x, int y) const = 0;
};

// 具体享元类 ConcreteFlyweight（黑棋）
class BlackPiece : public GoPiece
{
public:
    void display(int x, int y) const override
    {
        std::cout << "Black piece at (" << x << ", " << y << ")" << std::endl;
    }
};

// 具体享元类 ConcreteFlyweight（白棋）
class WhitePiece : public GoPiece
{
public:
    void display(int x, int y) const override
    {
        std::cout << "White piece at (" << x << ", " << y << ")" << std::endl;
    }
};

// 享元工厂类 Flyweight Factory
class GoPieceFactory
{
private:
    std::unordered_map<std::string, std::shared_ptr<GoPiece>> pieces;

public:
    // 获取共享棋子
    std::shared_ptr<GoPiece> getPiece(const std::string &color)
    {
        if (pieces.find(color) == pieces.end()) {
            if (color == "black") {
                pieces[color] = std::make_shared<BlackPiece>();
            } else if (color == "white") {
                pieces[color] = std::make_shared<WhitePiece>();
            } else {
                throw std::invalid_argument("Invalid color");
            }
        }
        return pieces[color];
    }

    // 获取棋子总数（用于验证享元模式的效果）
    size_t getPieceCount() const { return pieces.size(); }
};

// 主函数
int main()
{
    GoPieceFactory factory;

    // 创建多个棋子（共享内部状态）
    auto black1 = factory.getPiece("black");
    auto black2 = factory.getPiece("black");
    auto white1 = factory.getPiece("white");
    auto white2 = factory.getPiece("white");

    // 显示棋子位置（外部状态）
    black1->display(1, 2);
    black2->display(2, 3);
    white1->display(3, 4);
    white2->display(4, 5);

    // 验证享元模式：只创建了两个共享的棋子对象
    std::cout << "Total unique pieces created: " << factory.getPieceCount() << std::endl;

    return 0;
}
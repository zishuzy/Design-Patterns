#include <iostream>
#include <vector>

class Visitor; // 前向声明

class Element
{
public:
    virtual ~Element() = default;
    virtual void accept(Visitor &visitor) = 0; // 接受访问者
};

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual void visit(class ConcreteElementA &element) = 0;
    virtual void visit(class ConcreteElementB &element) = 0;
};

class ConcreteElementA : public Element
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this); // 调用访问者的访问方法
    }

    void operationA() { std::cout << "Operation A" << std::endl; }
};

class ConcreteElementB : public Element
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this); // 调用访问者的访问方法
    }

    void operationB() { std::cout << "Operation B" << std::endl; }
};

class ConcreteVisitor : public Visitor
{
public:
    void visit(ConcreteElementA &element) override
    {
        std::cout << "Visiting ConcreteElementA" << std::endl;
        element.operationA(); // 访问具体元素A
    }

    void visit(ConcreteElementB &element) override
    {
        std::cout << "Visiting ConcreteElementB" << std::endl;
        element.operationB(); // 访问具体元素B
    }
};

int main()
{
    // 创建元素对象
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    // 创建访问者对象
    ConcreteVisitor visitor;

    // 让元素接受访问者
    elementA.accept(visitor);
    elementB.accept(visitor);

    return 0;
}
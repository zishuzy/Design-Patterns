#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 备忘录类
class Memento
{
private:
    std::string state; // 保存的状态

public:
    explicit Memento(const std::string &s)
        : state(s)
    {
    }
    std::string getState() const { return state; }
};

// 发起人类
class Editor
{
private:
    std::string content; // 当前文档内容

public:
    void write(const std::string &text) { content += text; }

    void display() const { std::cout << "Current Content: " << content << std::endl; }

    // 创建备忘录
    std::shared_ptr<Memento> save() const { return std::make_shared<Memento>(content); }

    // 恢复到备忘录状态
    void restore(const std::shared_ptr<Memento> &memento)
    {
        if (memento) {
            content = memento->getState();
        }
    }
};

// 管理者类
class Caretaker
{
private:
    std::vector<std::shared_ptr<Memento>> history;

public:
    void save(const std::shared_ptr<Memento> &memento) { history.push_back(memento); }

    std::shared_ptr<Memento> undo()
    {
        if (!history.empty()) {
            auto memento = history.back();
            history.pop_back();
            return memento;
        }
        return nullptr;
    }
};

int main()
{
    // 创建编辑器和管理者
    Editor editor;
    Caretaker caretaker;

    // 写入内容并保存状态
    editor.write("Hello, ");
    caretaker.save(editor.save());

    editor.write("World!");
    caretaker.save(editor.save());

    editor.write(" Haha!");

    editor.display(); // 输出：Hello, World! Haha!

    // 撤销操作
    std::cout << "Undoing..." << std::endl;
    editor.restore(caretaker.undo());
    editor.display(); // 输出：Hello, World!

    std::cout << "Undoing again..." << std::endl;
    editor.restore(caretaker.undo());
    editor.display(); // 输出： Hello,

    return 0;
}
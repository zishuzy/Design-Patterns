#include <iostream>
#include <vector>
#include <memory>
#include <string>

// 抽象基类 Component
class FileSystemComponent
{
public:
    virtual ~FileSystemComponent() = default;

    virtual void display(int indent = 0) const = 0;
};

// 叶子节点 File
class File : public FileSystemComponent
{
private:
    std::string name;

public:
    explicit File(const std::string &name)
        : name(name)
    {
    }

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "- " << name << std::endl;
    }
};

// 组合节点 Directory
class Directory : public FileSystemComponent
{
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    explicit Directory(const std::string &name)
        : name(name)
    {
    }

    void add(const std::shared_ptr<FileSystemComponent> &component)
    {
        children.push_back(component);
    }

    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "+ " << name << std::endl;
        for (const auto &child : children) {
            child->display(indent + 2);
        }
    }
};

// 主函数
int main()
{
    // 创建文件和目录
    auto root = std::make_shared<Directory>("root");
    auto dir1 = std::make_shared<Directory>("dir1");
    auto dir2 = std::make_shared<Directory>("dir2");

    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");
    auto file3 = std::make_shared<File>("file3.txt");

    // 构建目录树
    dir1->add(file1);
    dir1->add(file2);

    dir2->add(file3);

    root->add(dir1);
    root->add(dir2);

    // 显示目录结构
    root->display();

    return 0;
}
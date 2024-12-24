#include <iostream>
#include <string>
#include <memory>

// 图像接口（抽象主题）
class Image
{
public:
    virtual ~Image() = default;
    virtual void display() const = 0;
};

// 真实图像（真实主题）
class HighResolutionImage : public Image
{
private:
    std::string filename;

    void loadFromDisk() const
    {
        std::cout << "Loading high-resolution image from disk: " << filename << std::endl;
    }

public:
    explicit HighResolutionImage(const std::string &file)
        : filename(file)
    {
        loadFromDisk(); // 模拟高成本的操作
    }

    void display() const override
    {
        std::cout << "Displaying high-resolution image: " << filename << std::endl;
    }
};

// 图像代理（代理）
class ImageProxy : public Image
{
private:
    std::string filename;
    mutable std::shared_ptr<HighResolutionImage> realImage; // 延迟加载的真实图像

public:
    explicit ImageProxy(const std::string &file)
        : filename(file)
        , realImage(nullptr)
    {
    }

    void display() const override
    {
        if (!realImage) { // 如果真实图像未加载，则加载
            realImage = std::make_shared<HighResolutionImage>(filename);
        }
        realImage->display();
    }
};

class Subject
{
public:
    virtual void Request() const = 0;
};

class RealSubject : public Subject
{
public:
    void Request() const override { std::cout << "RealSubject: Handling request.\n"; }
};

class Proxy : public Subject
{
private:
    std::shared_ptr<RealSubject> real_subject_;

    bool CheckAccess() const
    {
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void LogAccess() const { std::cout << "Proxy: Logging the time of request.\n"; }

public:
    Proxy(std::shared_ptr<RealSubject> real_subject)
        : real_subject_(real_subject)
    {
    }

    void Request() const override
    {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};

// 主函数
int main()
{
    // 使用代理来创建图像
    std::shared_ptr<Image> image = std::make_shared<ImageProxy>("example.jpg");

    // 图像尚未加载
    std::cout << "Image proxy created. No image loaded yet." << std::endl;

    // 显示图像，触发延迟加载
    std::cout << "First display:" << std::endl;
    image->display();

    // 再次显示图像，不需要重新加载
    std::cout << "Second display:" << std::endl;
    image->display();

    std::cout << "\n" << std::endl;

    std::cout << "Client: Executing the client code with a real subject:\n";
    std::shared_ptr<RealSubject> real_subject = std::make_shared<RealSubject>();
    real_subject->Request();
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>(real_subject);
    proxy->Request();

    return 0;
}
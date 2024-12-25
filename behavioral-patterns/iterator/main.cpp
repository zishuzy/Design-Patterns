#include <iostream>
#include <vector>
#include <memory>
#include <string>

// 书类
class Book
{
private:
    std::string title_;

public:
    explicit Book(const std::string &t)
        : title_(t)
    {
    }
    std::string getTitle() const { return title_; }
};

// 抽象迭代器接口
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;         // 检查是否还有元素
    virtual std::shared_ptr<Book> next() = 0; // 获取下一个元素
};

// 抽象集合接口
class Aggregate
{
public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator> createIterator() const = 0; // 创建迭代器
};

// 具体集合类：书架
class Bookshelf : public Aggregate
{
private:
    std::vector<std::shared_ptr<Book>> books_;

public:
    void addBook(const std::shared_ptr<Book> &book) { books_.push_back(book); }

    std::shared_ptr<Book> getBookAt(size_t index) const
    {
        if (index < books_.size()) {
            return books_[index];
        }
        return nullptr;
    }

    size_t getSize() const { return books_.size(); }

    // 实现创建迭代器的方法
    std::unique_ptr<Iterator> createIterator() const override;
};

// 具体迭代器类
class BookshelfIterator : public Iterator
{
private:
    const Bookshelf &bookshelf_;
    size_t index_;

public:
    explicit BookshelfIterator(const Bookshelf &bs)
        : bookshelf_(bs)
        , index_(0)
    {
    }

    bool hasNext() const override { return index_ < bookshelf_.getSize(); }

    std::shared_ptr<Book> next() override
    {
        if (!hasNext()) {
            return nullptr;
        }
        return bookshelf_.getBookAt(index_++);
    }
};

// 书架实现创建迭代器的方法
std::unique_ptr<Iterator> Bookshelf::createIterator() const
{
    return std::make_unique<BookshelfIterator>(*this);
}

// 主函数
int main()
{
    // 创建书架并添加书籍
    Bookshelf bookshelf;
    bookshelf.addBook(std::make_shared<Book>("C++ Programming"));
    bookshelf.addBook(std::make_shared<Book>("Design Patterns"));
    bookshelf.addBook(std::make_shared<Book>("Data Structures"));

    // 使用迭代器遍历书架
    auto iterator = bookshelf.createIterator();
    while (iterator->hasNext()) {
        auto book = iterator->next();
        if (book) {
            std::cout << "Book: " << book->getTitle() << std::endl;
        }
    }

    return 0;
}
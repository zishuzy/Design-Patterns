#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 抽象中介者接口
class Mediator
{
public:
    virtual ~Mediator() = default;
    virtual void sendMessage(const std::string &message, const std::string &senderName) = 0;
    virtual void addUser(std::shared_ptr<class User> user) = 0;
};

// 抽象用户类
class User
{
protected:
    Mediator &mediator;
    std::string name;

public:
    User(Mediator &m, const std::string &n)
        : mediator(m)
        , name(n)
    {
    }
    virtual ~User() = default;

    virtual void send(const std::string &message) { mediator.sendMessage(message, name); }

    virtual void receive(const std::string &message, const std::string &senderName)
    {
        std::cout << "[" << name << "] received message from [" << senderName << "]: " << message
                  << std::endl;
    }

    std::string getName() const { return name; }
};

// 具体中介者类
class ChatRoom : public Mediator
{
private:
    std::vector<std::shared_ptr<User>> users;

public:
    void sendMessage(const std::string &message, const std::string &senderName) override
    {
        for (const auto &user : users) {
            if (user->getName() != senderName) {
                user->receive(message, senderName);
            }
        }
    }

    void addUser(std::shared_ptr<User> user) override
    {
        users.push_back(user);
        std::cout << "[" << user->getName() << "] joined the chat room." << std::endl;
    }
};

// 具体用户类
class ChatUser : public User
{
public:
    ChatUser(Mediator &m, const std::string &n)
        : User(m, n)
    {
    }
};

int main()
{
    // 创建聊天室中介者
    ChatRoom chatRoom;

    // 创建用户
    auto user1 = std::make_shared<ChatUser>(chatRoom, "Alice");
    auto user2 = std::make_shared<ChatUser>(chatRoom, "Bob");
    auto user3 = std::make_shared<ChatUser>(chatRoom, "Charlie");

    // 添加用户到聊天室
    chatRoom.addUser(user1);
    chatRoom.addUser(user2);
    chatRoom.addUser(user3);

    // 用户之间发送消息
    user1->send("Hello, everyone!");
    user2->send("Hi, Alice!");
    user3->send("Hello, Alice and Bob!");

    return 0;
}
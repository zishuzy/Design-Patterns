#include <iostream>
#include <thread>

#include "singleton.hpp"

int main(int argc, char *argv[])
{

    auto t1 = std::thread([] {
        for (int i = 0; i < 10000; i++) {
            Singleton::GetInstance().AddValue(1);
        }
    });
    auto t2 = std::thread([] {
        for (int i = 0; i < 10000; i++) {
            Singleton::GetInstance().AddValue(1);
        }
    });

    t1.join();
    t2.join();

    std::cout << Singleton::GetInstance().GetValue() << std::endl;

    return 0;
}

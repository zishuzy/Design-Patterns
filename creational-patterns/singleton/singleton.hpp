/**
 * @file singleton.hpp
 * @author zishu (zishuzy@gmail.com)
 * @brief 单例
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __SINGLETON_SINGLETON__
#define __SINGLETON_SINGLETON__

#include <atomic>

class Singleton
{
public:
    static Singleton &GetInstance()
    {
        static Singleton inst;
        return inst;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    void AddValue(int value) { value_.fetch_add(value); }
    int GetValue() const { return value_; }

private:
    Singleton() = default;

    std::atomic<int> value_ = 0;
};

#endif /* __SINGLETON_SINGLETON__ */

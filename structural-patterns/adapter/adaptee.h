/**
 * @file adaptee.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 需要适配的类
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __ADAPTER_ADAPTEE__
#define __ADAPTER_ADAPTEE__

#include <string>

namespace adapter
{
class CAdaptee
{
public:
    virtual ~CAdaptee() = default;
    virtual std::string SpecificRequest();
};
} // namespace adapter

#endif /* __ADAPTER_ADAPTEE__ */

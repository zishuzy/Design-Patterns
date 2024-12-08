/**
 * @file implementation.hpp
 * @author zishu (zishuzy@gmail.com)
 * @brief 实现接口
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BRIDGE_IMPLEMENTATION__
#define __BRIDGE_IMPLEMENTATION__

#include <string>

namespace bridge
{
class IImplementation
{
public:
    virtual ~IImplementation() = default;

    virtual std::string OperationImplementation() const = 0;
};
} // namespace bridge

#endif /* __BRIDGE_IMPLEMENTATION__ */

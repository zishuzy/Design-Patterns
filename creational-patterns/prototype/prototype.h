/**
 * @file prototype.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 原型类抽象接口
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __PROTOTYPE_PROTOTYPE__
#define __PROTOTYPE_PROTOTYPE__

namespace prototype
{
class IPrototype
{
public:
    virtual ~IPrototype() = default;

    virtual IPrototype *Clone() = 0;
};
} // namespace prototype

#endif /* __PROTOTYPE_PROTOTYPE__ */

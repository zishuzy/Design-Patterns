/**
 * @file prototype_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 原型 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __PROTOTYPE_PROTOTYPE_A__
#define __PROTOTYPE_PROTOTYPE_A__

#include "prototype.h"

namespace prototype
{
class PrototypeA : public IPrototype
{
public:
    explicit PrototypeA(int value);
    PrototypeA(const PrototypeA &other);
    virtual ~PrototypeA() = default;

    IPrototype *Clone() override;

    int GetValue() const;

private:
    int value_;
};

}; // namespace prototype

#endif /* __PROTOTYPE_PROTOTYPE_A__ */

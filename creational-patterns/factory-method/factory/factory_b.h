/**
 * @file factory_b.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体工厂 B
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __FACTORY_FACTORY_B__
#define __FACTORY_FACTORY_B__

#include "factory.hpp"

namespace factory_method
{
class CFactoryB : public IFactory
{
public:
    CFactoryB() = default;
    virtual ~CFactoryB() = default;

    virtual IProduct *CreateProduct() const override;
};
} // namespace factory_method

#endif /* __FACTORY_FACTORY_B__ */

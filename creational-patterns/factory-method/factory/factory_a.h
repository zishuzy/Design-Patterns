/**
 * @file factory_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体工厂 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __FACTORY_FACTORY_A__
#define __FACTORY_FACTORY_A__

#include "factory.hpp"

namespace factory_method
{
class CFactoryA : public IFactory
{
public:
    CFactoryA() = default;
    virtual ~CFactoryA() = default;

    virtual IProduct *CreateProduct() const override;
};
} // namespace factory_method

#endif /* __FACTORY_FACTORY_A__ */

/**
 * @file factory_2.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体工厂 2
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __FACTORY_FACTORY_2__
#define __FACTORY_FACTORY_2__

#include "factory.hpp"

namespace abstract_factory
{
class CFactory2 : public IFactory
{
public:
    CFactory2() = default;
    virtual ~CFactory2() = default;

    virtual IProductA *CreateProductA() const override;
    virtual IProductB *CreateProductB() const override;
};
} // namespace abstract_factory

#endif /* __FACTORY_FACTORY_2__ */

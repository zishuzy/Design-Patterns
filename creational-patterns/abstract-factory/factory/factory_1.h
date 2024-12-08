/**
 * @file factory_1.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体工厂 1
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __FACTORY_FACTORY_1__
#define __FACTORY_FACTORY_1__

#include "factory.hpp"

namespace abstract_factory
{
class CFactory1 : public IFactory
{
public:
    CFactory1() = default;
    virtual ~CFactory1() = default;

    virtual IProductA *CreateProductA() const override;
    virtual IProductB *CreateProductB() const override;
};
} // namespace abstract_factory

#endif /* __FACTORY_FACTORY_1__ */

/**
 * @file factory.hpp
 * @author zishu (zishuzy@gmail.com)
 * @brief 抽象工厂接口
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __FACTORY_FACTORY__
#define __FACTORY_FACTORY__

#include "product/product.hpp"

namespace abstract_factory
{
class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual IProductA *CreateProductA() const = 0;
    virtual IProductB *CreateProductB() const = 0;
};
} // namespace abstract_factory

#endif /* __FACTORY_FACTORY__ */

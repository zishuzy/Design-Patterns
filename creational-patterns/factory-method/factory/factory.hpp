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

namespace factory_method
{
class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual IProduct *CreateProduct() const = 0;
};
} // namespace factory_method

#endif /* __FACTORY_FACTORY__ */

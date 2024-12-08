/**
 * @file product.hpp
 * @author zishu (zishuzy@gmail.com)
 * @brief 抽象产品接口
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __PRODUCT_PRODUCT__
#define __PRODUCT_PRODUCT__

namespace abstract_factory
{
class IProductA
{
public:
    virtual ~IProductA() = default;

    virtual void OperationA() const = 0;
};

class IProductB
{
public:
    virtual ~IProductB() = default;

    virtual void OperationB() const = 0;
};
} // namespace abstract_factory

#endif /* __PRODUCT_PRODUCT__ */

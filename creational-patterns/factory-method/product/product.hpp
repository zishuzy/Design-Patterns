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

namespace factory_method
{
class IProduct
{
public:
    virtual ~IProduct() = default;

    virtual void Operation() const = 0;
};
} // namespace factory_method

#endif /* __PRODUCT_PRODUCT__ */

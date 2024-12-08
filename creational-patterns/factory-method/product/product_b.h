/**
 * @file product_b.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体产品 B
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __PRODUCT_PRODUCT_B__
#define __PRODUCT_PRODUCT_B__

#include "product.hpp"

namespace factory_method
{

class CProductB : public IProduct
{
public:
    void Operation() const override;
};
} // namespace factory_method

#endif /* __PRODUCT_PRODUCT_B__ */

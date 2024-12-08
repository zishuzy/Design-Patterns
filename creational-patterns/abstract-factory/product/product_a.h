/**
 * @file product_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体产品 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __PRODUCT_PRODUCT_A__
#define __PRODUCT_PRODUCT_A__

#include "product.hpp"

namespace abstract_factory
{
class CProductA1 : public IProductA
{
public:
    virtual void OperationA() const override;
};

class CProductA2 : public IProductA
{
public:
    virtual void OperationA() const override;
};
} // namespace abstract_factory

#endif /* __PRODUCT_PRODUCT_A__ */

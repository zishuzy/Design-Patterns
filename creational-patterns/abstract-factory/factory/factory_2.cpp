#include "factory_2.h"

#include "product/product_a.h"
#include "product/product_b.h"

namespace abstract_factory
{
IProductA *CFactory2::CreateProductA() const
{
    return new CProductA2();
}

IProductB *CFactory2::CreateProductB() const
{
    return new CProductB2();
}
} // namespace abstract_factory
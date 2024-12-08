#include "factory_1.h"

#include "product/product_a.h"
#include "product/product_b.h"

namespace abstract_factory
{
IProductA *CFactory1::CreateProductA() const
{
    return new CProductA1();
}

IProductB *CFactory1::CreateProductB() const
{
    return new CProductB1();
}
} // namespace abstract_factory
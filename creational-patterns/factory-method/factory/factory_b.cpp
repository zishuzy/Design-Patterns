#include "factory_b.h"

#include "product/product_b.h"

namespace factory_method
{
IProduct *CFactoryB::CreateProduct() const
{
    return new CProductB();
}
} // namespace factory_method
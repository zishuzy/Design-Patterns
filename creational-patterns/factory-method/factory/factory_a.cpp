#include "factory_a.h"

#include "product/product_a.h"

namespace factory_method
{
IProduct *CFactoryA::CreateProduct() const
{
    return new CProductA();
}
} // namespace factory_method
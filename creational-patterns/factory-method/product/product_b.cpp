#include "product_b.h"
#include <iostream>

namespace factory_method
{
void CProductB::Operation() const
{
    std::cout << "Operation of Product B" << std::endl;
}
} // namespace factory_method
#include "product_a.h"
#include <iostream>

namespace factory_method
{
void CProductA::Operation() const
{
    std::cout << "Operation of Product A" << std::endl;
}
} // namespace factory_method
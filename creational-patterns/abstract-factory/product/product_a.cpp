#include "product_a.h"
#include <iostream>

namespace abstract_factory
{
void CProductA1::OperationA() const
{
    std::cout << "Operation of Product A1" << std::endl;
}

void CProductA2::OperationA() const
{
    std::cout << "Operation of Product A2" << std::endl;
}
} // namespace abstract_factory
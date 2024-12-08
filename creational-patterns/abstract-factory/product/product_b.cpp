#include "product_b.h"
#include <iostream>

namespace abstract_factory
{
void CProductB1::OperationB() const
{
    std::cout << "Operation of Product B1" << std::endl;
}

void CProductB2::OperationB() const
{
    std::cout << "Operation of Product B2" << std::endl;
}
} // namespace abstract_factory
#include "product_b.h"

namespace builder
{

void CProductB::SetPartA(const std::string &part_a)
{
    part_a_ = part_a;
}
void CProductB::SetPartB(const std::string &part_b)
{
    part_b_ = part_b;
}
void CProductB::SetPartC(const std::string &part_c)
{
    part_c_ = part_c;
}

std::string CProductB::ToString() const
{
    return "CProductB: part_a[" + part_a_ + "], part_b[" + part_b_ + "], part_c[" +
           part_c_ + "]";
}
} // namespace builder
#include "product_a.h"

namespace builder
{

void CProductA::SetPart1(const std::string &part_1)
{
    part_1_ = part_1;
}
void CProductA::SetPart2(const std::string &part_2)
{
    part_2_ = part_2;
}
void CProductA::SetPart3(const std::string &part_3)
{
    part_3_ = part_3;
}

std::string CProductA::ToString() const
{
    return "CProductA: part_1[" + part_1_ + "], part_2[" + part_2_ + "], part_3[" +
           part_3_ + "]";
}
} // namespace builder
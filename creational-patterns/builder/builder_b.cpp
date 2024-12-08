#include "builder_b.h"

namespace builder
{

CBuilderB::CBuilderB()
    : product_(new CProductB())
{
}

CBuilderB::~CBuilderB()
{
    delete product_;
}

void CBuilderB::BuildPart1()
{
    product_->SetPartA("builder B part 1");
}

void CBuilderB::BuildPart2()
{
    product_->SetPartB("builder B part 2");
}

void CBuilderB::BuildPart3()
{
    product_->SetPartC("builder B part 3");
}
} // namespace builder
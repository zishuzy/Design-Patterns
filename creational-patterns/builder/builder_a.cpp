#include "builder_a.h"

namespace builder
{

CBuilderA::CBuilderA()
    : product_(new CProductA())
{
}

CBuilderA::~CBuilderA()
{
    delete product_;
}

void CBuilderA::BuildPart1()
{
    product_->SetPart1("builder A part 1");
}

void CBuilderA::BuildPart2()
{
    product_->SetPart2("builder A part 2");
}

void CBuilderA::BuildPart3()
{
    product_->SetPart3("builder A part 3");
}
} // namespace builder
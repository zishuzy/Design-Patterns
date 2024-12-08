#include "director.h"

namespace builder
{

CDirector::CDirector(IBuilder *builder)
    : builder_(builder)
{
}

CDirector::~CDirector() {}

void CDirector::BuildMiniProduct()
{
    builder_->BuildPart1();
}

void CDirector::BuildFullProduct()
{
    builder_->BuildPart1();
    builder_->BuildPart2();
    builder_->BuildPart3();
}

} // namespace builder
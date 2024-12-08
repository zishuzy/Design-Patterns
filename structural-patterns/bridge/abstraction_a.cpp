#include "abstraction_a.h"

namespace bridge
{
CAbstractionA::CAbstractionA(std::shared_ptr<IImplementation> impl)
    : CAbstraction(impl)
{
}

std::string CAbstractionA::Operation() const
{
    return "extended: " + impl_->OperationImplementation();
}

} // namespace bridge
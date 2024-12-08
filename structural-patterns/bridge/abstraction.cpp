#include "abstraction.h"

namespace bridge
{
CAbstraction::CAbstraction(std::shared_ptr<IImplementation> impl)
    : impl_(impl)
{
}

std::string CAbstraction::Operation() const
{
    return "base: " + impl_->OperationImplementation();
}

} // namespace bridge
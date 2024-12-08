#include "prototype_a.h"

namespace prototype
{

PrototypeA::PrototypeA(int value)
    : value_(value)
{
}

PrototypeA::PrototypeA(const PrototypeA &other)
    : value_(other.value_)
{
}

IPrototype *PrototypeA::Clone()
{
    return new PrototypeA(*this);
}

int PrototypeA::GetValue() const
{
    return value_;
}
}; // namespace prototype
#include "adapter.h"

#include <algorithm>

namespace adapter
{
CAdapter::CAdapter(CAdaptee *adaptee)
    : adaptee_(adaptee)
{
}

std::string CAdapter::Request()
{
    std::string req = adaptee_->SpecificRequest();
    std::reverse(req.begin(), req.end());
    return req;
}
} // namespace adapter
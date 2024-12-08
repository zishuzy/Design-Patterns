#include "adaptee.h"

namespace adapter
{
std::string CAdaptee::SpecificRequest()
{
    std::string req = "CAdaptee::SpecificRequest()";
    std::reverse(req.begin(), req.end());
    return req;
}
} // namespace adapter
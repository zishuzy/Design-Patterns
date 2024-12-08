/**
 * @file implementation_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体实现 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BRIDGE_IMPLEMENTATION_A__
#define __BRIDGE_IMPLEMENTATION_A__

#include "implementation.hpp"

namespace bridge
{

class CImplementationA : public IImplementation
{
public:
    CImplementationA() = default;
    virtual ~CImplementationA() = default;

    std::string OperationImplementation() const override;
};

} // namespace bridge

#endif /* __BRIDGE_IMPLEMENTATION_A__ */

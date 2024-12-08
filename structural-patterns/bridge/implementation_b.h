/**
 * @file implementation_b.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 具体实现 B
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BRIDGE_IMPLEMENTATION_B__
#define __BRIDGE_IMPLEMENTATION_B__

#include "implementation.hpp"

namespace bridge
{

class CImplementationB : public IImplementation
{
public:
    CImplementationB() = default;
    virtual ~CImplementationB() = default;

    std::string OperationImplementation() const override;
};

} // namespace bridge

#endif /* __BRIDGE_IMPLEMENTATION_B__ */

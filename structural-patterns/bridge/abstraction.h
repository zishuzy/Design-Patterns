/**
 * @file abstraction.h
 * @author zishu (zishuzy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __BRIDGE_ABSTRACTION__
#define __BRIDGE_ABSTRACTION__

#include "implementation.hpp"

#include <memory>

namespace bridge
{

class CAbstraction
{
public:
    explicit CAbstraction(std::shared_ptr<IImplementation> impl);
    virtual ~CAbstraction() = default;
    virtual std::string Operation() const;

protected:
    std::shared_ptr<IImplementation> impl_;
};

} // namespace bridge

#endif /* __BRIDGE_ABSTRACTION__ */

/**
 * @file abstraction_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BRIDGE_ABSTRACTION_A__
#define __BRIDGE_ABSTRACTION_A__

#include "abstraction.h"

namespace bridge
{

class CAbstractionA : public CAbstraction
{
public:
    explicit CAbstractionA(std::shared_ptr<IImplementation> impl);
    virtual ~CAbstractionA() = default;

    virtual std::string Operation() const override;
};

} // namespace bridge

#endif /* __BRIDGE_ABSTRACTION_A__ */

/**
 * @file target.hpp
 * @author zishu (zishuzy@gmail.com)
 * @brief 目标类
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __STRUCTURAL_PATTERNS_TARGET__
#define __STRUCTURAL_PATTERNS_TARGET__

#include <string>

namespace adapter
{

class CTarget
{
public:
    virtual ~CTarget() = default;

    virtual std::string Request();
};

} // namespace adapter

#endif /* __STRUCTURAL_PATTERNS_TARGET__ */

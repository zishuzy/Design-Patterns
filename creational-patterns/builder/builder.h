/**
 * @file builder.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 抽象建造接口
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_BUILDER__
#define __BUILDER_BUILDER__

namespace builder
{
class IBuilder
{
public:
    virtual ~IBuilder() = default;

    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;
};
} // namespace builder

#endif /* __BUILDER_BUILDER__ */

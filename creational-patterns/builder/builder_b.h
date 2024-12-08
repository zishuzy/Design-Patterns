/**
 * @file builder_b.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 建造者 B
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_BUILDER_B__
#define __BUILDER_BUILDER_B__

#include "builder.h"
#include "product_b.h"

namespace builder
{
class CBuilderB : public IBuilder
{
public:
    CBuilderB();
    virtual ~CBuilderB();

    virtual void BuildPart1() override;
    virtual void BuildPart2() override;
    virtual void BuildPart3() override;

    CProductB *GetProduct() const { return product_; }

private:
    CProductB *product_;
};
} // namespace builder

#endif /* __BUILDER_BUILDER_B__ */

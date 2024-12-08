/**
 * @file builder_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 建造者 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_BUILDER_A__
#define __BUILDER_BUILDER_A__

#include "builder.h"
#include "product_a.h"

namespace builder
{
class CBuilderA : public IBuilder
{
public:
    CBuilderA();
    virtual ~CBuilderA();

    virtual void BuildPart1() override;
    virtual void BuildPart2() override;
    virtual void BuildPart3() override;

    CProductA *GetProduct() const { return product_; }

private:
    CProductA *product_;
};
} // namespace builder

#endif /* __BUILDER_BUILDER_A__ */

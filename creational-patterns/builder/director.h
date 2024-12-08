/**
 * @file director.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 主管类
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_DIRECTOR__
#define __BUILDER_DIRECTOR__

#include "builder.h"

namespace builder
{
class CDirector
{
public:
    explicit CDirector(IBuilder *builder);
    virtual ~CDirector();

    void BuildMiniProduct();
    void BuildFullProduct();

private:
    IBuilder *builder_;
};
} // namespace builder

#endif /* __BUILDER_DIRECTOR__ */

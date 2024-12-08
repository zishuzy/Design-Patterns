/**
 * @file adapter.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 适配器
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __ADAPTER_ADAPTER__
#define __ADAPTER_ADAPTER__

#include "adaptee.h"
#include "target.h"

namespace adapter
{
class CAdapter : public CTarget
{
public:
    explicit CAdapter(CAdaptee *adaptee);
    virtual ~CAdapter() = default;
    virtual std::string Request() override;

private:
    CAdaptee *adaptee_;
};
} // namespace adapter

#endif /* __ADAPTER_ADAPTER__ */

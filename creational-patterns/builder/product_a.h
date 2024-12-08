/**
 * @file product_a.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 产品 A
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_PRODUCT_A__
#define __BUILDER_PRODUCT_A__

#include <string>

namespace builder
{
class CProductA
{
public:
    CProductA() = default;
    virtual ~CProductA() = default;

    void SetPart1(const std::string &part_1);
    void SetPart2(const std::string &part_2);
    void SetPart3(const std::string &part_3);

    std::string ToString() const;

private:
    std::string part_1_;
    std::string part_2_;
    std::string part_3_;
};
} // namespace builder

#endif /* __BUILDER_PRODUCT_A__ */

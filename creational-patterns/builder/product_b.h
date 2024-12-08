/**
 * @file product_b.h
 * @author zishu (zishuzy@gmail.com)
 * @brief 产品 B
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __BUILDER_PRODUCT_B__
#define __BUILDER_PRODUCT_B__

#include <string>

namespace builder
{
class CProductB
{
public:
    CProductB() = default;
    virtual ~CProductB() = default;

    void SetPartA(const std::string &part_a);
    void SetPartB(const std::string &part_b);
    void SetPartC(const std::string &part_c);

    std::string ToString() const;

private:
    std::string part_a_;
    std::string part_b_;
    std::string part_c_;
};
} // namespace builder

#endif /* __BUILDER_PRODUCT_B__ */

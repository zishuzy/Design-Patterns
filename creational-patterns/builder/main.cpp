#include <iostream>

#include "director.h"
#include "builder_a.h"
#include "builder_b.h"
#include "product_a.h"
#include "product_b.h"

int main(int argc, char *argv[])
{

    {
        builder::CBuilderA *builder_a = new builder::CBuilderA();
        builder::CDirector *director = new builder::CDirector(builder_a);
        director->BuildMiniProduct();
        auto product_mini = builder_a->GetProduct();
        std::cout << "Mini product:" << std::endl;
        std::cout << product_mini->ToString() << std::endl;

        director->BuildFullProduct();
        auto product_full = builder_a->GetProduct();
        std::cout << "Full product:" << std::endl;
        std::cout << product_full->ToString() << std::endl;
    }

    {
        builder::CBuilderB *builder_b = new builder::CBuilderB();
        builder::CDirector *director = new builder::CDirector(builder_b);
        director->BuildMiniProduct();
        auto product_mini = builder_b->GetProduct();
        std::cout << "Mini product:" << std::endl;
        std::cout << product_mini->ToString() << std::endl;

        director->BuildFullProduct();
        auto product_full = builder_b->GetProduct();
        std::cout << "Full product:" << std::endl;
        std::cout << product_full->ToString() << std::endl;
    }

    return 0;
}

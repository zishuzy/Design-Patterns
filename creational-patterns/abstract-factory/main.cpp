#include <iostream>

#include "factory/factory_1.h"
#include "factory/factory_2.h"
#include "product/product.hpp"

int main(int argc, char *argv[])
{
    abstract_factory::IFactory *factory1 = new abstract_factory::CFactory1();
    abstract_factory::IFactory *factory2 = new abstract_factory::CFactory2();
    abstract_factory::IProductA *productA1 = factory1->CreateProductA();
    abstract_factory::IProductB *productB1 = factory1->CreateProductB();
    abstract_factory::IProductA *productA2 = factory2->CreateProductA();
    abstract_factory::IProductB *productB2 = factory2->CreateProductB();

    std::cout << "Factory 1" << std::endl;
    productA1->OperationA();
    productB1->OperationB();
    delete productA1;
    delete productB1;

    std::cout << "Factory 2" << std::endl;
    productA2->OperationA();
    productB2->OperationB();
    delete productA2;
    delete productB2;

    return 0;
}

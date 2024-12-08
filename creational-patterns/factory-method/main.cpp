#include <iostream>

#include "factory/factory_a.h"
#include "factory/factory_b.h"
#include "product/product.hpp"

int main(int argc, char *argv[])
{
    factory_method::IFactory *factorya = new factory_method::CFactoryA();
    factory_method::IFactory *factoryb = new factory_method::CFactoryB();
    factory_method::IProduct *producta = factorya->CreateProduct();
    factory_method::IProduct *productb = factoryb->CreateProduct();

    producta->Operation();
    productb->Operation();

    delete producta;
    delete productb;

    return 0;
}

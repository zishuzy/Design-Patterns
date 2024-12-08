#include <iostream>

#include "abstraction_a.h"
#include "implementation_a.h"
#include "implementation_b.h"

int main(int argc, char *argv[])
{
    bridge::CAbstraction *abstraction =
        new bridge::CAbstraction(std::make_shared<bridge::CImplementationA>());
    std::cout << "abstraction: " << abstraction->Operation() << std::endl;
    delete abstraction;

    abstraction = new bridge::CAbstractionA(std::make_shared<bridge::CImplementationB>());
    std::cout << "abstraction: " << abstraction->Operation() << std::endl;
    delete abstraction;

    return 0;
}

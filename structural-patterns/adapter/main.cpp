#include <iostream>

#include "target.h"
#include "adaptee.h"
#include "adapter.h"

int main(int argc, char *argv[])
{
    adapter::CTarget *target = new adapter::CTarget();
    std::cout << "target: " << target->Request() << std::endl;

    adapter::CAdaptee *adaptee = new adapter::CAdaptee();
    std::cout << "adaptee: " << adaptee->SpecificRequest() << std::endl;

    adapter::CAdapter *adapter = new adapter::CAdapter(adaptee);
    std::cout << "adapter: " << adapter->Request() << std::endl;

    return 0;
}

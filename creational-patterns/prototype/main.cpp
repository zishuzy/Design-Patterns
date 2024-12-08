#include <iostream>

#include "prototype_a.h"

int main(int argc, char *argv[])
{
    prototype::PrototypeA *prototype = new prototype::PrototypeA(1234);
    prototype::PrototypeA *prototype_clone =
        dynamic_cast<prototype::PrototypeA *>(prototype->Clone());
    std::cout << prototype->GetValue() << std::endl;
    std::cout << prototype_clone->GetValue() << std::endl;

    return 0;
}

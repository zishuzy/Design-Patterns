#include "state_home.h"

#include <iostream>

#include "context.h"
#include "state_scanning.h"

namespace state
{
void CStateHome::Scan()
{
    context_->TransitionTo(new CStateScanning());
}

void CStateHome::ScanFinish()
{
    std::cout << "Invalid operation. Home cannot be scanned." << std::endl;
}

void CStateHome::Repair()
{
    std::cout << "Invalid operation. Home cannot be repaired." << std::endl;
}

void CStateHome::RepairFinish()
{
    std::cout << "Invalid operation. Home cannot be repaired." << std::endl;
}

void CStateHome::Parse()
{
    std::cout << "Invalid operation. Home cannot be paused." << std::endl;
}

void CStateHome::Abort()
{
    std::cout << "Invalid operation. Home cannot be aborted." << std::endl;
}

void CStateHome::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
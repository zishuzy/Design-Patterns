#include "state_scanned.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_scanning.h"
#include "state_repairing.h"

namespace state
{
void CStateScanned::Scan()
{
    context_->TransitionTo(new CStateScanning());
}

void CStateScanned::ScanFinish()
{
    std::cout << "Invalid operation. Scanned cannot be scanned." << std::endl;
}

void CStateScanned::Repair()
{
    context_->TransitionTo(new CStateRepairing());
}

void CStateScanned::RepairFinish()
{
    std::cout << "Invalid operation. Scanned cannot be repaired." << std::endl;
}

void CStateScanned::Parse()
{
    std::cout << "Invalid operation. Scanned cannot be paused." << std::endl;
}

void CStateScanned::Abort()
{
    std::cout << "Invalid operation. Scanned cannot be aborted." << std::endl;
}

void CStateScanned::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
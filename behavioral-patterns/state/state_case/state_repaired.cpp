#include "state_repaired.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_scanning.h"

namespace state
{
void CStateRepaired::Scan()
{
    context_->TransitionTo(new CStateScanning());
}

void CStateRepaired::ScanFinish()
{
    std::cout << "Invalid operation. Repaired cannot be scanned." << std::endl;
}

void CStateRepaired::Repair()
{
    std::cout << "Invalid operation. Repaired cannot be repairing." << std::endl;
}

void CStateRepaired::RepairFinish()
{
    std::cout << "Invalid operation. Repaired cannot be repaired." << std::endl;
}

void CStateRepaired::Parse()
{
    std::cout << "Invalid operation. Repaired cannot be paused." << std::endl;
}

void CStateRepaired::Abort()
{
    std::cout << "Invalid operation. Repaired cannot be aborted." << std::endl;
}

void CStateRepaired::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
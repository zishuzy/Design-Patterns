#include "state_repairing.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_repaired.h"
#include "state_repair_pausing.h"

namespace state
{
void CStateRepairing::Scan()
{
    std::cout << "Invalid operation. Repairing cannot be scanning." << std::endl;
}

void CStateRepairing::ScanFinish()
{
    std::cout << "Invalid operation. Repairing cannot be scanned." << std::endl;
}

void CStateRepairing::Repair()
{
    std::cout << "Invalid operation. Repairing cannot be repairing." << std::endl;
}

void CStateRepairing::RepairFinish()
{
    context_->TransitionTo(new CStateRepaired());
}

void CStateRepairing::Parse()
{
    context_->TransitionTo(new CStateRepairPausing());
}

void CStateRepairing::Abort()
{
    std::cout << "Invalid operation. Repairing cannot be aborted." << std::endl;
}

void CStateRepairing::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
#include "state_repair_pausing.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_repairing.h"
#include "state_repair_aborting.h"

namespace state
{
void CStateRepairPausing::Scan()
{
    std::cout << "Invalid operation. Repair Pausing cannot be scaning." << std::endl;
}
void CStateRepairPausing::ScanFinish()
{
    std::cout << "Invalid operation. Repair Pausing cannot be scanned." << std::endl;
}

void CStateRepairPausing::Repair()
{
    context_->TransitionTo(new CStateRepairing());
}

void CStateRepairPausing::RepairFinish()
{
    std::cout << "Invalid operation. Repair Pausing cannot be repaired." << std::endl;
}

void CStateRepairPausing::Parse()
{
    std::cout << "Invalid operation. Repair Pausing cannot be paused." << std::endl;
}

void CStateRepairPausing::Abort()
{
    context_->TransitionTo(new CStateRepairAborting());
}

void CStateRepairPausing::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
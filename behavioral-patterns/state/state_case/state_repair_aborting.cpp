#include "state_repair_aborting.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_repaired.h"

namespace state
{
void CStateRepairAborting::Scan()
{
    std::cout << "Invalid operation. Repair Aborting cannot be scaning." << std::endl;
}

void CStateRepairAborting::ScanFinish()
{
    std::cout << "Invalid operation. Repair Aborting cannot be scanned." << std::endl;
}

void CStateRepairAborting::Repair()
{
    std::cout << "Invalid operation. Repair Aborting cannot be repairing." << std::endl;
}

void CStateRepairAborting::RepairFinish()
{
    context_->TransitionTo(new CStateRepaired());
}

void CStateRepairAborting::Parse()
{
    std::cout << "Invalid operation. Repair Aborting cannot be paused." << std::endl;
}

void CStateRepairAborting::Abort()
{
    std::cout << "Invalid operation. Repair Aborting cannot be aborted." << std::endl;
}

void CStateRepairAborting::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
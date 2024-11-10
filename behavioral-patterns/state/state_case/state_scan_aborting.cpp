#include "state_scan_aborting.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_scanned.h"

namespace state
{
void CStateScanAborting::Scan()
{
    std::cout << "Invalid operation. Scan Aborting cannot be scaning." << std::endl;
}

void CStateScanAborting::ScanFinish()
{
    context_->TransitionTo(new CStateScanned());
}

void CStateScanAborting::Repair()
{
    std::cout << "Invalid operation. Scan Aborting cannot be repairing." << std::endl;
}

void CStateScanAborting::RepairFinish()
{
    std::cout << "Invalid operation. Scan Aborting cannot be repaired." << std::endl;
}

void CStateScanAborting::Parse()
{
    std::cout << "Invalid operation. Scan Aborting cannot be paused." << std::endl;
}

void CStateScanAborting::Abort()
{
    std::cout << "Invalid operation. Scan Aborting cannot be aborted." << std::endl;
}

void CStateScanAborting::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
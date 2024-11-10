#include "state_scan_pausing.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_scanning.h"
#include "state_scan_aborting.h"

namespace state
{
void CStateScanPausing::Scan()
{
    context_->TransitionTo(new CStateScanning());
}

void CStateScanPausing::ScanFinish()
{
    std::cout << "Invalid operation. Scan Pausing cannot be scanned." << std::endl;
}

void CStateScanPausing::Repair()
{
    std::cout << "Invalid operation. Scan Pausing cannot be repairing." << std::endl;
}

void CStateScanPausing::RepairFinish()
{
    std::cout << "Invalid operation. Scan Pausing cannot be repaired." << std::endl;
}

void CStateScanPausing::Parse()
{
    std::cout << "Invalid operation. Scan Pausing cannot be paused." << std::endl;
}

void CStateScanPausing::Abort()
{
    context_->TransitionTo(new CStateScanAborting());
}

void CStateScanPausing::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
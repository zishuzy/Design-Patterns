#include "state_scanning.h"

#include <iostream>

#include "context.h"
#include "state_home.h"
#include "state_scanned.h"
#include "state_scan_pausing.h"

namespace state
{
void CStateScanning::Scan()
{
    std::cout << "Invalid operation. Scanning cannot be scaning." << std::endl;
}

void CStateScanning::ScanFinish()
{
    context_->TransitionTo(new CStateScanned());
}

void CStateScanning::Repair()
{

    std::cout << "Invalid operation. Scanning cannot be repairing." << std::endl;
}

void CStateScanning::RepairFinish()
{

    std::cout << "Invalid operation. Scanning cannot be repaired." << std::endl;
}

void CStateScanning::Parse()
{
    context_->TransitionTo(new CStateScanPausing());
}

void CStateScanning::Abort()
{
    std::cout << "Invalid operation. Scanning cannot be aborted." << std::endl;
}

void CStateScanning::Reset()
{
    context_->TransitionTo(new CStateHome());
}

} // namespace state
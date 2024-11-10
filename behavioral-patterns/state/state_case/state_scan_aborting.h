#ifndef __STATE_CASE_STATE_SCAN_ABORTING__
#define __STATE_CASE_STATE_SCAN_ABORTING__

#include "state.h"

namespace state
{
class CStateScanAborting : public CState
{
public:
    void Scan() override;
    void ScanFinish() override;
    void Repair() override;
    void RepairFinish() override;
    void Parse() override;
    void Abort() override;
    void Reset() override;
};
} // namespace state

#endif /* __STATE_CASE_STATE_SCAN_ABORTING__ */

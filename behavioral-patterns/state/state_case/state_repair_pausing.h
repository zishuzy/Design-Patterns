#ifndef __STATE_CASE_STATE_REPAIR_PAUSING__
#define __STATE_CASE_STATE_REPAIR_PAUSING__

#include "state.h"

namespace state
{
class CStateRepairPausing : public CState
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

#endif /* __STATE_CASE_STATE_REPAIR_PAUSING__ */

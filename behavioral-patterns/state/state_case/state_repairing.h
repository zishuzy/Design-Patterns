#ifndef __STATE_CASE_STATE_REPAIRING__
#define __STATE_CASE_STATE_REPAIRING__

#include "state.h"

namespace state
{
class CStateRepairing : public CState
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

#endif /* __STATE_CASE_STATE_REPAIRING__ */

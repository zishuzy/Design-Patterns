#ifndef __STATE_STATE_HOME__
#define __STATE_STATE_HOME__

#include "state.h"

namespace state
{
class CStateHome : public CState
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

#endif /* __STATE_STATE_HOME__ */

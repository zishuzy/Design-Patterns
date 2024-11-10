#ifndef __STATE_CONTEXT__
#define __STATE_CONTEXT__

#include "state_event.hpp"

namespace state
{
class CState;

class CContext : public IStateEvent
{
public:
    CContext(CState *state);
    virtual ~CContext();

    void TransitionTo(CState *state);

    void Scan() override;
    void ScanFinish() override;
    void Repair() override;
    void RepairFinish() override;
    void Parse() override;
    void Abort() override;
    void Reset() override;

private:
    CState *state_;
};
} // namespace state

#endif /* __STATE_CONTEXT__ */

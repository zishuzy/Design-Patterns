#ifndef __STATE_STATE__
#define __STATE_STATE__

#include "state_event.hpp"

namespace state
{
class CContext;

class CState : public IStateEvent
{
public:
    virtual ~CState() {}

    void SetContext(CContext *context) { this->context_ = context; }

protected:
    CContext *context_;
};

} // namespace state

#endif /* __STATE_STATE__ */

#include "context.h"
#include <iostream>

#include "state.h"

namespace state
{
CContext::CContext(CState *state)
    : state_(nullptr)
{
    this->TransitionTo(state);
}

CContext::~CContext()
{
    delete state_;
}

void CContext::TransitionTo(CState *state)
{

    std::cout << "Context: Transition form "
              << (state_ == nullptr ? "no state" : typeid(*state_).name()) << " to "
              << typeid(*state).name() << ".\n";
    if (state_ != nullptr) {
        delete state_;
    }
    state_ = state;
    state_->SetContext(this);
}

void CContext::Scan()
{
    state_->Scan();
}

void CContext::ScanFinish()
{
    state_->ScanFinish();
}

void CContext::Repair()
{
    state_->Repair();
}

void CContext::RepairFinish()
{
    state_->RepairFinish();
}

void CContext::Parse()
{
    state_->Parse();
}

void CContext::Abort()
{
    state_->Abort();
}

void CContext::Reset()
{
    state_->Reset();
}

} // namespace state
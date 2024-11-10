#include "state.h"
#include "context.h"

#include "state_case/state_home.h"

int main(int argc, char *argv[])
{
    state::CContext *context = new state::CContext(new state::CStateHome());

    context->Scan();
    context->Parse();
    context->Scan();
    context->ScanFinish();
    context->Repair();
    context->Parse();
    context->Repair();
    context->RepairFinish();
    context->Reset();

    return 0;
}

#pragma once
#include "event.h"
namespace fsmgen
{
    template<typename EventEnum>
    class Fsm
    {
    public:
        void update();
        void dispatchEvent(const Event&&);
    };
} // namespace fsmgen
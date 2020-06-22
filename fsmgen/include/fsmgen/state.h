#pragma once

namespace fsmgen
{
    class State
    {
        public:
        State() {}
        virtual void onEntry() {}
        virtual void onUpdate() {}
        virtual void onExit() {}
        virtual ~State() {}
    };
} // namespace fsmgen
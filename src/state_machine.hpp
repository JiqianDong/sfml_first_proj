#pragma once
#include <memory>
#include <stack>

#include "state.hpp"

namespace Flappy
{
    typedef std::unique_ptr<State> state_ref;

    class State_machine
    {

    public:
        State_machine(/* args */){};
        ~State_machine(){};
        void add_state(state_ref new_state, bool is_replacing = true);
        void remove_state();
        void process_state_changes();
        state_ref &get_active_state(); // return by reference
    private:
        std::stack<state_ref> _states;
        state_ref _new_state;
        bool _is_removing;
        bool _is_adding;
        bool _is_replacing;
    };

} // namespace Flappy

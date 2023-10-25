#include "state_machine.hpp"

namespace Flappy
{
    void State_machine::add_state(state_ref new_state, bool is_replacing)
    {
        this->_is_adding = true;
        this->_is_replacing = is_replacing;
        this->_new_state = std::move(new_state); // TODO:understand this
    }

    void State_machine::remove_state()
    {
        this->_is_removing = true;
    }

    void State_machine::process_state_changes()
    {
        if (this->_is_removing && !this->_states.empty())
        {
            this->_states.pop();
            if (!this->_states.empty())
            {
                this->_states.top()->resume();
            }
            this->_is_removing = false;
        }
        if (this->_is_adding)
        {
            if (!this->_states.empty())
            {
                if (this->_is_replacing)
                {
                    this->_states.pop();
                }
                else{
                    this->_states.top()->pause();
                }
            }
        }
    }

} // namespace Flappy

#include "StateMachine.h"

namespace Breakout {

	void StateMachine::addState(StateRef newState, bool replacing)
	{
		this->_adding = true;
		this->_replacing = replacing;

		this->newState = std::move(newState);
	}
	void StateMachine::removeState( ) 
	{ 
		this->_removing = true;
	}

	void StateMachine::changeState() {
		if (this->_removing && !this->_states.empty())
		{
			this->_states.pop();
			if (!this->_states.empty())
			{
				this->_states.top( )->Resume( );
			}
			this->_removing = false;
		}
		if (this->_adding)
		{
			if (!this->_states.empty( ))
			{
				if (this->_replacing)
					{
					this->_states.pop();
					}
					else
					{
						this->_states.top( )->Pause( );
					}
				}
				this->_states.push(std::move(this->newState));
				this->_states.top()->initialState();
				this->_adding = false;
			}
		}
		StateRef &StateMachine::GetActiveState()
		{
			return this->_states.top( );
		}
}



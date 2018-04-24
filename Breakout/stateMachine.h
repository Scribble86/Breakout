#pragma once 

#include <memory> 
#include <stack> //states will be depending on the stack in the game 
#include "state.h"
 

namespace Breakout {

	typedef std::unique_ptr<State> StateRef;
	class StateMachine 
	{
	public:
		StateMachine() {}
		~StateMachine() {}

		void addState(StateRef newState, bool replacing = true);
		void removeState();

		void changeState();

		StateRef &GetActiveState( );

	private:
		std::stack<StateRef> _states;
		StateRef newState;

		bool _removing;
		bool _adding;
		bool _replacing;
		
	};

}
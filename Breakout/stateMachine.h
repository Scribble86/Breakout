#include "Header.h"
#include "state.h"
 
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
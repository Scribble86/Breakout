#pragma once 

//to keep all our clases separated 
namespace Breakout {
	class State
	{
	public:
		virtual void initialState( )= 0;
		virtual void HandleImput( ) = 0 ; 
		virtual void Update(float delta) = 0; //if there is a change 
		virtual void Draw(float delta) = 0;

		void Pause() {}
		void Resume() {}
	};
}
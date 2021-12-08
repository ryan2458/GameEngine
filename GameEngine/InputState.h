/*
Authors: Anne Tansengco
*/

#ifndef INPUT_STATE_H
#define INPUT_STATE_H

// if a new key needs to be added, needs to be declared here as extern bool
// must be declared extern bool to be visible during translation and linking phase of compilation
namespace InputState
{
	namespace KeyPressed
	{
		extern bool left, right, down, up;
		extern bool e, q;
		extern bool key_1, key_2, key_3, key_4;
		extern bool space;
	};
};

#endif
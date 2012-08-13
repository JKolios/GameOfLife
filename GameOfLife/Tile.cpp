#include <iostream>
#include "Tile.h"

using namespace std;


Tile::Tile(bool initialState)
{
	state = initialState;
}
Tile::Tile()
{
	state = false;
}
bool Tile::getState()
{

	return state;
}
void Tile::setState(bool newState)
{
	state = newState;
};
void Tile::toggleState()
{
	state = !state;
};
void Tile::printState()
{
	if(state == true)
	{cout << "Alive";
	}
	else cout << "Dead";
};
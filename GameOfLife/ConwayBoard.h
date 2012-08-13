#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
class ConwayBoard{
private:
	int Height;
	int Width;
	bool **boardTiles;
public:
	ConwayBoard();
	ConwayBoard(int Width_in,int Height_in);
	bool getTileState(int tileWidth,int tileHeight);
	void setTileState(int tileWidth,int tileHeight,bool state);
	void printTileState(int tileWidth,int tileHeight);
	void toggleTileState(int tileWidth,int tileHeight);
	void Iterate();
	void printBoard(std::ostream&);
	void randomizeBoard();
};
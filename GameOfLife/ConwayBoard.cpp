#include "ConwayBoard.h"

#define DEFAULT_WIDTH 20
#define DEFAULT_HEIGHT 20
using namespace std;

ConwayBoard::ConwayBoard()
{
	Height = DEFAULT_WIDTH;
	Width = DEFAULT_HEIGHT;

	boardTiles = new bool*[DEFAULT_WIDTH];
	int i,j;
	for(i=0;i<Height;i++) boardTiles[i] = new bool[DEFAULT_HEIGHT];

	for (i=0;i<Height;i++){
		for (j=0;j<Width;j++){
			boardTiles[i][j] = false;
		}
	}


}

ConwayBoard::ConwayBoard(int Width_in, int Height_in)
{
	Width = Width_in;
	Height = Height_in;

	boardTiles = new bool*[Width];
	int i,j;
	for(i=0;i<Height;i++) boardTiles[i] = new bool[Height]; 

	for (i=0;i<Height;i++){
		for (j=0;j<Width;j++){
			boardTiles[i][j] = false;
		}
	}


}

void ConwayBoard::setTileState(int tileWidth,int tileHeight,bool state)
{
	boardTiles[tileHeight][tileWidth] = (state);

}

bool ConwayBoard::getTileState(int tileWidth,int tileHeight)
{
	return boardTiles[tileHeight][tileWidth];

}

void ConwayBoard::toggleTileState(int tileWidth,int tileHeight)
{
	boardTiles[tileHeight][tileWidth] = !boardTiles[tileHeight][tileWidth];

}

void ConwayBoard::printTileState(int tileWidth,int tileHeight)
{
	cout << boardTiles[tileHeight][tileWidth];

}

void ConwayBoard::Iterate()
{
	bool** newBoard = new bool*[Width];
	int i,j;
	for(i=0;i<Height;i++) newBoard[i] = new bool[Height];

	for (i=0;i<Height;i++){
		for (j=0;j<Width;j++){

			int live_neighbors = 0;

			//Up

			if(i != 0){
				if (boardTiles[i-1][j]) live_neighbors++; 
				//...and to the left
				if(j != 0){
					if (boardTiles[i-1][j-1]) live_neighbors++;
				}
				//...and to the right
				if(j != (Width-1)){
					if (boardTiles[i-1][j+1]) live_neighbors++;
				}
			}
			//Down
			if(i != (Height-1)){
				if (boardTiles[i+1][j]) live_neighbors++;
				//...and to the left
				if(j != 0){
					if (boardTiles[i+1][j-1]) live_neighbors++;
				}
				//...and to the right
				if(j != (Width-1)){
					if (boardTiles[i+1][j+1]) live_neighbors++;
				}
			}
			//Left
			if(j != 0){
				if (boardTiles[i][j-1]) live_neighbors++; 
			}
			//Right
			if(j != (Width-1)){
				if (boardTiles[i][j+1]) live_neighbors++; 
			}


			//The Cell was alive at the beginning of the current iteration
			if ((boardTiles[i][j]))
			{
				if(live_neighbors < 2) {
					newBoard[i][j] = false;
				}else if (live_neighbors > 3) {
					newBoard[i][j] = false;	
				}else newBoard[i][j] = true;
			}
			//The Cell was dead at the beginning of the current iteration
			else if (live_neighbors == 3) {
				newBoard[i][j] = true;
			}else{
				newBoard[i][j] = false;
			}


		}
	}

	for(i=0;i<Height;i++)
	{
		for(j=0;j<Height;j++)
		{
			boardTiles[i][j] = newBoard[i][j];
		}
	}

	for (i=0;i<Height;i++) free(newBoard[i]);
	free(newBoard);
}

void ConwayBoard::printBoard(std::ostream &stream){
	int i,j;
	for (i=0;i<Height;i++){
		for (j=0;j<Width;j++){
			if ((boardTiles[i][j]) == true) {
				stream << "* ";
			}
			else{
				stream << "- ";
			}
		}
		stream << endl;
	}
}

void ConwayBoard::randomizeBoard()
{
	int i,j;
	srand((unsigned int)time(NULL));
	for (i=0;i<Height;i++){
		for (j=0;j<Width;j++){
			if ((rand() % 2) == 0) boardTiles[i][j] = false;
			else boardTiles[i][j] = true;
		}
	}
}
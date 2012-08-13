#include <iostream>
#include <fstream>
#include "ConwayBoard.h"

using namespace std;

int options()
{
	int option = -1;

	do{

		cout << endl;
		cout << "1:Toggle tile condition." << endl;
		cout << "2:Proceed one iteration." << endl;
		cout << "3:Proceed multiple iterations." << endl;
		cout << "4:Print Board." << endl;
		cout << "5:Print Iterations to file." << endl;
		cout << "6:Create new Board." << endl;
		cout << "7:Randomly fill board." << endl;
		cout << "0:Quit." << endl;
		cout << "Selection:";
		cin >> option;
	}while ((option < 0) || (option > 9));
	return option;
}

int main(int argc,char* argv)
{
	int width,height;
	int current_iteration = 0;
	cout << "Conway's game of life." << endl;
	cout << "Board Width:";
	cin >> width; 
	cout << "Board Height:";
	cin >> height;
	ConwayBoard *activeBoard = new ConwayBoard(width,height);
	while(1)
	{

		switch(options()){
		case 1:{
			int height,width;
			cout << "Tile Width:";
			cin >> width; 
			cout << "Tile Height:";
			cin >> height;
			cout << "Previous state:";  
			activeBoard->printTileState(width,height);
			cout << endl;
			activeBoard->toggleTileState(width,height);
			cout << "Current state:";
			activeBoard->printTileState(width,height);
			cout << endl;
			break;
			   }

		case 2:{
			activeBoard->Iterate();
			current_iteration++;
			cout << "Current iteration:" << current_iteration << endl;;
			break;
			   }
		case 3:{
			int i,iterationCount;
			cout << "Iteration Count:";
			cin >> iterationCount; 
			for(i=0;i<iterationCount;i++) activeBoard->Iterate();
			current_iteration += iterationCount;
			cout << "Current iteration:" << current_iteration << endl;;
			break;
			   }

		case 4:{
			activeBoard->printBoard(cout);

			break;
			   }
		case 5:{
			ofstream outfile("outfile.txt",fstream::out);
			int i,iterationCount;
			cout << "Iteration Count:";
			cin >> iterationCount;
			for(i=0;i<iterationCount;i++)
			{
				outfile << "Iteration " << current_iteration << endl;;
				activeBoard->printBoard(outfile);
				outfile << endl;
				activeBoard->Iterate();
				current_iteration++;
			}
			outfile.close();
			break;
			   }
		case 6:{
			int width,height;
			cout << "Board Width:";
			cin >> width; 
			cout << "Board Height:";
			cin >> height;
			activeBoard = new ConwayBoard(width,height);
			cout << "\nNew Board Created with dimensions:Width:" << width <<" Height:" << height <<endl;
			current_iteration = 0;

			break;
			   }
		case 7:{
			activeBoard->randomizeBoard();
			cout << "Board Randomized.New board state:" << endl;
			activeBoard->printBoard(cout);			

			break;
			   }
		case 0:{
			return 0;
			   }
		}
	}
}
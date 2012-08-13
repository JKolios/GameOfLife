

class Tile {
private:
	bool state;
public:
	Tile(bool initialState);
	Tile();
	bool getState();
	void setState(bool newState);
	void toggleState();
	void printState();
};
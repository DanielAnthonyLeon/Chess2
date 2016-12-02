#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"
#include <fstream>

class Game {
private:
	Board *m_board;
	PieceColour m_turn;
public:
	Game();
	bool makeMove(char file1, int rank1, char file2, int rank2);
	void changeTurn();
	void playGame();
	void playGameFromFile(std::string gameFile);
};

#endif /* Game_hpp */

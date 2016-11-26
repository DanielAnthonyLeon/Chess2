#ifndef Board_hpp
#define Board_hpp

#include "Square.hpp"
#include <string>

class Square;

class Board {
private:
	Square *m_board[8][8];
public:
	Board();
	~Board();
	Square* getSquare(char file, int rank);
};

#endif /* Board_hpp */

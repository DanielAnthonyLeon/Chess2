#ifndef Board_hpp
#define Board_hpp

#include "Square.hpp"
#include <string>
#include <iostream>

class Square;

class Board {
private:
	Square *m_board[8][8];
public:
	Board();
	~Board();
	Square* getSquare(char file, int rank) const;
	friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif /* Board_hpp */

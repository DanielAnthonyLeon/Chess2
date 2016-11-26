#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

class Bishop : public Piece {
public:
	Bishop(char file, int rank, Board *board, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Bishop_hpp */

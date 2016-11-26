#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece {
public:
	Knight(char file, int rank, Board *board, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Knight_hpp */

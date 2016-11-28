#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece {
public:
	Knight(PieceColour colour);
	std::string symbol();
	void setSquaresInRange(char file, int rank, Board *board);
};

#endif /* Knight_hpp */

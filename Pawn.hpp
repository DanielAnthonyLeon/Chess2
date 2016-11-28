#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece {
public:
	Pawn(PieceColour colour);
	std::string symbol();
	void setSquaresInRange(char file, int rank, Board *board);
};

#endif /* Pawn_hpp */

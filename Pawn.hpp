#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece {
public:
	Pawn(char file, int rank, Board *board, PieceColour colour);
	void setSquaresInRange();
};

#endif /* Pawn_hpp */

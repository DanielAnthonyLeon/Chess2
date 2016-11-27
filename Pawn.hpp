#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece {
public:
	Pawn(Square *square, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Pawn_hpp */

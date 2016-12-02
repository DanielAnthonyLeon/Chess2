#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

class Rook : public Piece {
public:
	Rook(PieceColour colour);
	std::string symbol();
	void setSquaresInRange(Board *board);
};

#endif /* Rook_hpp */

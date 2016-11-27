#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

class Rook : public Piece {
public:
	Rook(Square *square, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Rook_hpp */

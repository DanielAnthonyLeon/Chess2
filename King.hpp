#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

class King : public Piece {
public:
	King(Square *square, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* King_hpp */

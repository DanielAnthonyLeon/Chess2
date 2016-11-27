#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece {
public:
	Knight(Square *m_square, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Knight_hpp */

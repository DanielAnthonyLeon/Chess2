#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

class King : public Piece {
public:
	King(PieceColour colour);
	std::string symbol();
	void setSquaresInRange(char file, int rank, Board *board);
};

#endif /* King_hpp */

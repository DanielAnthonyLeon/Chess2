#ifndef Queen_hpp
#define Queen_hpp

#include "Piece.hpp"

class Queen : public Piece {
public:
	Queen(PieceColour colour);
	std::string symbol();
	void setSquaresInRange(Board *board);
};

#endif /* Queen_hpp */

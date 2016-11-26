#ifndef Queen_hpp
#define Queen_hpp

#include "Piece.hpp"

class Queen : public Piece {
public:
	Queen(char file, int rank, Board *board, PieceColour colour);
	std::string symbol();
	void setSquaresInRange();
};

#endif /* Queen_hpp */

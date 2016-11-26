#ifndef Piece_hpp
#define Piece_hpp

#include "Square.hpp"
#include "Board.hpp"
#include <vector>

class Square;
class Board;

enum PieceType {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum PieceColour {
	WHITE,
	BLACK
};

class Piece {
protected:
	char m_file;
	int m_rank;
	Board *m_board;
	PieceType m_type;
	PieceColour m_colour;
	std::vector<Square*> m_squaresInRange;
public:
	Piece(char file, int rank, Board *board, PieceType type, PieceColour colour);
	PieceType getType();
	PieceColour getColour();
	int colourIncrement();
	virtual void setSquaresInRange() = 0;
};

#endif /* Piece_hpp */

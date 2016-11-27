#ifndef Piece_hpp
#define Piece_hpp

#include "Square.hpp"
#include <vector>
#include <string>

class Square;

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
	Square *m_square;
	PieceType m_type;
	PieceColour m_colour;
	std::vector<Square*> m_squaresInRange;
public:
	Piece(Square *square, PieceType type, PieceColour colour);
	Square* getSquare();
	PieceType getType();
	PieceColour getColour();
	virtual std::string symbol() = 0;
	int colourIncrement();
	virtual void setSquaresInRange() = 0;
};

#endif /* Piece_hpp */

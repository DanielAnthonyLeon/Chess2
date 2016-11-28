#ifndef Piece_hpp
#define Piece_hpp

#include <vector>
#include <string>

class Square;
class Board;

enum PieceType : unsigned int {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum PieceColour : unsigned int {
	WHITE,
	BLACK
};

class Piece {
protected:
	PieceType m_type;
	PieceColour m_colour;
	std::vector<Square*> m_squaresInRange;
public:
	Piece(PieceType type, PieceColour colour);
	PieceType getType();
	PieceColour getColour();
	virtual std::string symbol() = 0;
	int colourIncrement();
	virtual void setSquaresInRange(char file, int rank, Board *board) = 0;
};

#endif /* Piece_hpp */

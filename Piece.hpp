#ifndef Piece_hpp
#define Piece_hpp

#include <vector>
#include <string>
#include <iostream>

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
	Square *m_square;
	std::vector<Square*> m_squaresInRange;
	std::vector<Piece*> m_piecesAttacking;
	std::vector<Piece*> m_piecesAttackedBy;
public:
	Piece(PieceType type, PieceColour colour);
	PieceType getType();
	PieceColour getColour();
	Square* getSquare();
	void placeOnBoard(Square *square);
	virtual std::string symbol() = 0;
	int colourIncrement();
	virtual void setSquaresInRange(Board *board);
	void beingAttackedBy(Piece *piece);
	int numberOfAttackers();
	bool isMoveSemiLegal(Square *destination);
	void printMoves();
};

#endif /* Piece_hpp */

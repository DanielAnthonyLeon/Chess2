#include "Piece.hpp"

Piece::Piece(Square *square, PieceType type, PieceColour colour) :
m_square(square),
m_type(type),
m_colour(colour)
{
	
}

Square* Piece::getSquare() {
	return m_square;
}

PieceType Piece::getType() {
	return m_type;
}

PieceColour Piece::getColour() {
	return m_colour;
}

int Piece::colourIncrement() {
	return m_colour == WHITE ? 1 : -1;
}

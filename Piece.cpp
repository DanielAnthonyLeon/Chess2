#include "Piece.hpp"

Piece::Piece(PieceType type, PieceColour colour) :
m_type(type),
m_colour(colour)
{

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

#include "Piece.hpp"

Piece::Piece(char file, int rank, Board *board, PieceType type, PieceColour colour) :
m_file(file),
m_rank(rank),
m_board(board),
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

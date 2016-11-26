#include "Rook.hpp"

Rook::Rook(char file, int rank, Board *board, PieceColour colour) :
Piece(file, rank, board, ROOK, colour)
{
	
}

std::string Rook::symbol() {
	return m_colour == WHITE ? "♖" : "♜";
}

void Rook::setSquaresInRange() {
	for (int i = -7; i < 7; i++) {
		Square *s = m_board->getSquare(m_file+i, m_rank);
			// Square is on board
		if (s) {
				// Square is unoccupied
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
				// Square is occupied by opposite coloured piece
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
			}
		}
	}
	for (int i = -7; i < 7; i++) {
		Square *s = m_board->getSquare(m_file, m_rank+i);
		if (s) {
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
			}
		}
	}
}

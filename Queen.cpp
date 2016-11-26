#include "Queen.hpp"
#include "Rook.hpp"

Queen::Queen(char file, int rank, Board *board, PieceColour colour) :
	Piece(file, rank, board, QUEEN, colour)
{
	
}

std::string Queen::symbol() {
	return m_colour == WHITE ? "♕" : "♛";
}

void Queen::setSquaresInRange() {
		// Moves like a bishop
	for (int i = -7; i < 7; i++) {
		Square *s = m_board->getSquare(m_file+i, m_rank+i);
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
		Square *s = m_board->getSquare(m_file+i, m_rank-i);
		if (s) {
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
			}
		}
	}
		// Moves like a rook
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

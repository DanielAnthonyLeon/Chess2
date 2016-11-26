#include "Pawn.hpp"

Pawn::Pawn(char file, int rank, Board *board, PieceColour colour) :
Piece(file, rank, board, PAWN, colour)
{
	
}

std::string Pawn::symbol() {
	return m_colour == WHITE ? "♙" : "♟";
}

void Pawn::setSquaresInRange() {
	Square *front = m_board->getSquare(m_file+colourIncrement(), m_rank+colourIncrement());
	Square *frontLeft = m_board->getSquare(m_file-colourIncrement(), m_rank+colourIncrement());
	Square *frontRight = m_board->getSquare(m_file+colourIncrement(), m_rank+colourIncrement());
	
		// Square is on the board
	if (front) {
			// Square is unoccupied
		if (!front->isOccupied()) {
			m_squaresInRange.push_back(front);
		}
	}
	if (frontLeft) {
		if (!frontLeft->isOccupied()) {
			m_squaresInRange.push_back(frontLeft);
		}
			// Square has a piece that can be captured
		else if (frontLeft->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(frontLeft);
		}
	}
	if (frontRight) {
		if (!frontRight->isOccupied()) {
			m_squaresInRange.push_back(frontRight);
		}
		else if (frontRight->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(frontRight);
		}
	}
}

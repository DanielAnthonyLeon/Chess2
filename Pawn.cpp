#include "Pawn.hpp"

Pawn::Pawn(char file, int rank, Board *board, PieceColour colour) :
Piece(file, rank, board, PAWN, colour)
{
	
}

void Pawn::setSquaresInRange() {
	Square *front = m_board->getSquare(m_file+colourIncrement(), m_rank+colourIncrement());
	Square *frontLeft = m_board->getSquare(m_file-colourIncrement(), m_rank+colourIncrement());
	Square *frontRight = m_board->getSquare(m_file+colourIncrement(), m_rank+colourIncrement());
	
		// front square is on the board
	if (front) {
			// front square is unoccupied
		if (!front->hasPiece()) {
			m_squaresInRange.push_back(front);
		}
	}
	if (frontLeft) {
		if (!frontLeft->hasPiece()) {
			m_squaresInRange.push_back(frontLeft);
		}
		else if (frontLeft->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(frontLeft);
		}
	}
	if (frontRight) {
		if (!frontRight->hasPiece()) {
			m_squaresInRange.push_back(frontRight);
		}
		else if (frontRight->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(frontRight);
		}
	}
}

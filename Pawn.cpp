#include "Pawn.hpp"
#include "Board.hpp"

Pawn::Pawn(PieceColour colour) :
Piece(PAWN, colour)
{
	
}

std::string Pawn::symbol() {
	return m_colour == WHITE ? "♙" : "♟";
}

void Pawn::setSquaresInRange(char file, int rank, Board *board) {
	Square *front = board->getSquare(file+colourIncrement(), rank+colourIncrement());
	Square *frontLeft = board->getSquare(file-colourIncrement(), rank+colourIncrement());
	Square *frontRight = board->getSquare(file+colourIncrement(), rank+colourIncrement());
	
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

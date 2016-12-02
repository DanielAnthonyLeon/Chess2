#include "Pawn.hpp"
#include "Board.hpp"

Pawn::Pawn(PieceColour colour) :
Piece(PAWN, colour)
{
	
}

std::string Pawn::symbol() {
	return m_colour == WHITE ? "♙" : "♟";
}

bool Pawn::onStartingRank() {
	int rank = getSquare()->getRank();
	if (getColour() == WHITE) {
		return rank == 2;
	}
	else {
		return rank == 7;
	}
}

void Pawn::setSquaresInRange(Board *board) {
		// Empty the vector to start fresh
	Piece::setSquaresInRange(board);
	
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	Square *front = board->getSquare(file, rank+colourIncrement());
	Square *frontLeft = board->getSquare(file-colourIncrement(), rank+colourIncrement());
	Square *frontRight = board->getSquare(file+colourIncrement(), rank+colourIncrement());
	
		// If pawn hasn't moved yet
	if (onStartingRank()) {
		Square *twoInFront = board->getSquare(file, rank+2*colourIncrement());
		if (!front->isOccupied() && !twoInFront->isOccupied()) {
			m_squaresInRange.push_back(twoInFront);
		}
	}
	
		// Square is on the board
	if (front) {
			// Square is unoccupied
		if (!front->isOccupied()) {
			m_squaresInRange.push_back(front);
		}
	}
	if (frontLeft) {
		Piece *piece = frontLeft->getPiece();
			// There is a piece diagonal to the pawn
		if (piece) {
				// The piece is of opposite colour
			if (piece->getColour() != getColour()) {
				m_squaresInRange.push_back(frontLeft);
				Piece *piece = frontLeft->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
			}
		}
	}
	if (frontRight) {
		Piece *piece = frontRight->getPiece();
		if (piece) {
			if (piece->getColour() != getColour()) {
				m_squaresInRange.push_back(frontRight);
				Piece *piece = frontRight->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
			}
		}
	}
}

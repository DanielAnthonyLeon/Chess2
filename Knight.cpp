#include "Knight.hpp"
#include "Board.hpp"

Knight::Knight(PieceColour colour) :
Piece(KNIGHT, colour)
{
	
}

std::string Knight::symbol() {
	return m_colour == WHITE ? "♘" : "♞";
}

void Knight::setSquaresInRange(Board *board) {
		// Empty the vector to start fresh
	Piece::setSquaresInRange(board);
	
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	Square *upLeft = board->getSquare(file-1, rank+2);
	Square *upRight = board->getSquare(file+1, rank+2);
	Square *downLeft = board->getSquare(file-1, rank-2);
	Square *downRight = board->getSquare(file+1, rank-2);
	Square *rightUp = board->getSquare(file+2, rank+1);
	Square *rightDown = board->getSquare(file+2, rank-1);
	Square *leftUp = board->getSquare(file-2, rank+1);
	Square *leftDown = board->getSquare(file-2, rank-1);
	
		// Square is actually on board
	if (upLeft) {
			// Square is empty
		if (!upLeft->isOccupied()) {
			m_squaresInRange.push_back(upLeft);
		}
			// Piece is opposite colour
		else if (upLeft->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(upLeft);
			Piece *piece = upLeft->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (upRight) {
		if (!upRight->isOccupied()) {
			m_squaresInRange.push_back(upRight);
		}
		else if (upRight->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(upRight);
			Piece *piece = upRight->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (downLeft) {
		if (!downLeft->isOccupied()) {
			m_squaresInRange.push_back(downLeft);
		}
		else if (downLeft->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(downLeft);
			Piece *piece = downLeft->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (downRight) {
		if (!downRight->isOccupied()) {
			m_squaresInRange.push_back(downRight);
		}
		else if (downRight->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(downRight);
			Piece *piece = downRight->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (rightUp) {
		if (!rightUp->isOccupied()) {
			m_squaresInRange.push_back(rightUp);
		}
		else if (rightUp->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(rightUp);
			Piece *piece = rightUp->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (rightDown) {
		if (!rightDown->isOccupied()) {
			m_squaresInRange.push_back(rightDown);
		}
		else if (rightDown->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(rightDown);
			Piece *piece = rightDown->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (leftUp) {
		if (!leftUp->isOccupied()) {
			m_squaresInRange.push_back(leftUp);
		}
		else if (leftUp->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(leftUp);
			Piece *piece = leftUp->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
	if (leftDown) {
		if (!leftDown->isOccupied()) {
			m_squaresInRange.push_back(leftDown);
		}
		else if (leftDown->getPiece()->getColour() != getColour()) {
			m_squaresInRange.push_back(leftDown);
			Piece *piece = leftDown->getPiece();
			m_piecesAttacking.push_back(piece);
			piece->beingAttackedBy(this);
		}
	}
}

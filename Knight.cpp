#include "Knight.hpp"

Knight::Knight(Square *square, PieceColour colour) :
Piece(square, KNIGHT, colour)
{
	
}

std::string Knight::symbol() {
	return m_colour == WHITE ? "♘" : "♞";
}

void Knight::setSquaresInRange() {
	Board *board = getSquare()->getBoard();
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	Square *upLeft = board->getSquare(rank+2, file-1);
	Square *upRight = board->getSquare(rank+2, file+1);
	Square *downLeft = board->getSquare(rank-2, file-1);
	Square *downRight = board->getSquare(rank-2, file+1);
	Square *rightUp = board->getSquare(rank+1, file+2);
	Square *rightDown = board->getSquare(rank-1, file+2);
	Square *leftUp = board->getSquare(rank+1, file-2);
	Square *leftDown = board->getSquare(rank-1, file-2);
	
		// Square is actually on board
	if (upLeft) {
			// Square is empty
		if (!upLeft->isOccupied()) {
			m_squaresInRange.push_back(upLeft);
		}
			// Piece is opposite colour
		else if (upLeft->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(upLeft);
		}
	}
	if (upRight) {
		if (!upRight->isOccupied()) {
			m_squaresInRange.push_back(upRight);
		}
		else if (upRight->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(upRight);
		}
	}
	if (downLeft) {
		if (!downLeft->isOccupied()) {
			m_squaresInRange.push_back(downLeft);
		}
		else if (downLeft->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(downLeft);
		}
	}
	if (downRight) {
		if (!downRight->isOccupied()) {
			m_squaresInRange.push_back(downRight);
		}
		else if (upRight->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(downRight);
		}
	}
	if (rightUp) {
		if (!rightUp->isOccupied()) {
			m_squaresInRange.push_back(rightUp);
		}
		else if (rightUp->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(rightUp);
		}
	}
	if (rightDown) {
		if (!upRight->isOccupied()) {
			m_squaresInRange.push_back(rightDown);
		}
		else if (rightDown->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(rightDown);
		}
	}
	if (leftUp) {
		if (!upRight->isOccupied()) {
			m_squaresInRange.push_back(leftUp);
		}
		else if (leftUp->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(leftUp);
		}
	}
	if (leftDown) {
		if (!leftDown->isOccupied()) {
			m_squaresInRange.push_back(leftDown);
		}
		else if (leftDown->getPiece()->getColour() != m_colour) {
			m_squaresInRange.push_back(leftDown);
		}
	}
}

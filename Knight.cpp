#include "Knight.hpp"

Knight::Knight(char file, int rank, Board *board, PieceColour colour) :
Piece(file, rank, board, KNIGHT, colour)
{
	
}

std::string Knight::symbol() {
	return m_colour == WHITE ? "♘" : "♞";
}

void Knight::setSquaresInRange() {
	Square *upLeft = m_board->getSquare(m_rank+2, m_file-1);
	Square *upRight = m_board->getSquare(m_rank+2, m_file+1);
	Square *downLeft = m_board->getSquare(m_rank-2, m_file-1);
	Square *downRight = m_board->getSquare(m_rank-2, m_file+1);
	Square *rightUp = m_board->getSquare(m_rank+1, m_file+2);
	Square *rightDown = m_board->getSquare(m_rank-1, m_file+2);
	Square *leftUp = m_board->getSquare(m_rank+1, m_file-2);
	Square *leftDown = m_board->getSquare(m_rank-1, m_file-2);
	
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

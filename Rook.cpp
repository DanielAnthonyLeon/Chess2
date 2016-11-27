#include "Rook.hpp"

Rook::Rook(Square *square, PieceColour colour) :
Piece(square, ROOK, colour)
{
	
}

std::string Rook::symbol() {
	return m_colour == WHITE ? "♖" : "♜";
}

void Rook::setSquaresInRange() {
	Board *board = getSquare()->getBoard();
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	for (int i = 1; i <= 7 ; i++) {
		Square *s = board->getSquare(file+i, rank);
			// Square is on board
		if (s) {
				// Square is unoccupied
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
				// Square is occupied by opposite coloured piece
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
					// Rook cannot proceed any further
				break;
			}
				// Square is occupied by same coloured piece
			else {
				break;
			}
		}
			// Rook is off the board
		else {
			break;
		}
	}
	
	for (int i = 1; i <= 7 ; i++) {
		Square *s = board->getSquare(file, rank+i);
		if (s) {
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
				break;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
	
	for (int i = 1; i <= 7 ; i++) {
		Square *s = board->getSquare(file-i, rank);
		if (s) {
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
				break;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
	
	for (int i = 1; i <= 7 ; i++) {
		Square *s = board->getSquare(file, rank-i);
		if (s) {
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
				break;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
}

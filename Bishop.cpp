#include "Bishop.hpp"
#include "Board.hpp"

Bishop::Bishop(PieceColour colour) :
Piece(BISHOP, colour)
{
	
}

std::string Bishop::symbol() {
	return m_colour == WHITE ? "♗" : "♝";
}

void Bishop::setSquaresInRange(char file, int rank, Board *board) {
	for (int i = 1; i <= 7; i++) {
		Square *s = board->getSquare(file+i, rank+i);
			// Square is on board
		if (s) {
				// Square is unoccupied
			if (!s->isOccupied()) {
				m_squaresInRange.push_back(s);
			}
				// Square is occupied by opposite coloured piece
			else if (s->getPiece()->getColour() != m_colour) {
				m_squaresInRange.push_back(s);
					// Bishop can't go any further
				break;
			}
				// Square is occupied by same coloured piece
			else {
				break;
			}
		}
			// Bishop is off the board
		else {
			break;
		}
	}
	
	for (int i = 1; i <= 7; i++) {
		Square *s = board->getSquare(file+i, rank-i);
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
	
	for (int i = 1; i <= 7; i++) {
		Square *s = board->getSquare(file-i, rank+i);
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
	
	for (int i = 1; i <= 7; i++) {
		Square *s = board->getSquare(file-i, rank-i);
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

#include "Rook.hpp"
#include "Board.hpp"

Rook::Rook(PieceColour colour) :
Piece(ROOK, colour)
{
	
}

std::string Rook::symbol() {
	return m_colour == WHITE ? "♖" : "♜";
}

void Rook::setSquaresInRange(Board *board) {
		// Empty the vector to start fresh
	Piece::setSquaresInRange(board);
	
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	for (int i = 1; i <= 7 ; i++) {
		Square *square = board->getSquare(file+i, rank);
			// Square is on board
		if (square) {
				// Square is unoccupied
			if (!square->isOccupied()) {
				m_squaresInRange.push_back(square);
			}
				// Square is occupied by opposite coloured piece
			else if (square->getPiece()->getColour() != getColour()) {
				m_squaresInRange.push_back(square);
				Piece *piece = square->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
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
		Square *square = board->getSquare(file, rank+i);
		if (square) {
			if (!square->isOccupied()) {
				m_squaresInRange.push_back(square);
			}
			else if (square->getPiece()->getColour() != getColour()) {
				m_squaresInRange.push_back(square);
				Piece *piece = square->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
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
		Square *square = board->getSquare(file-i, rank);
		if (square) {
			if (!square->isOccupied()) {
				m_squaresInRange.push_back(square);
			}
			else if (square->getPiece()->getColour() != getColour()) {
				m_squaresInRange.push_back(square);
				Piece *piece = square->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
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
		Square *square = board->getSquare(file, rank-i);
		if (square) {
			if (!square->isOccupied()) {
				m_squaresInRange.push_back(square);
			}
			else if (square->getPiece()->getColour() != getColour()) {
				m_squaresInRange.push_back(square);
				Piece *piece = square->getPiece();
				m_piecesAttacking.push_back(piece);
				piece->beingAttackedBy(this);
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

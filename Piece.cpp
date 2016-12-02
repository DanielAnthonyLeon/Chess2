#include "Piece.hpp"
#include "Square.hpp"
#include "Board.hpp"

Piece::Piece(PieceType type, PieceColour colour) :
m_type(type),
m_colour(colour)
{

}

PieceType Piece::getType() {
	return m_type;
}

PieceColour Piece::getColour() {
	return m_colour;
}

Square* Piece::getSquare() {
	return m_square;
}

bool Piece::isAlive() {
	return m_square != NULL;
}

void Piece::kill() {
	m_square = NULL;
}

void Piece::pickup() {
	m_square->pickUpPiece();
	m_square = NULL;
}

void Piece::place(Square *square) {
		// Capture piece if the square is occupied
	Piece *previousPiece = square->getPiece();
	if (previousPiece) {
		previousPiece->kill();
	}
	
		// Piece now occupies the square
	m_square = square;
	m_square->placePiece(this);
}

int Piece::colourIncrement() {
	return m_colour == WHITE ? 1 : -1;
}

void Piece::setSquaresInRange(Board *board) {
		// Start over
	m_squaresInRange.erase(m_squaresInRange.begin(), m_squaresInRange.begin()+m_squaresInRange.size());
	m_piecesAttacking.erase(m_piecesAttacking.begin(), m_piecesAttacking.begin()+m_piecesAttacking.size());
	m_piecesAttackedBy.erase(m_piecesAttackedBy.begin(), m_piecesAttackedBy.begin()+m_piecesAttackedBy.size());
}

void Piece::beingAttackedBy(Piece *piece) {
	m_piecesAttackedBy.push_back(piece);
}

size_t Piece::numberOfAttackers() {
	return m_piecesAttackedBy.size();
}

bool Piece::isMoveSemiLegal(Square *destination) {
	for (Square *square : m_squaresInRange) {
		if (destination == square) {
			return true;
		}
	}
	return false;
}

void Piece::setLegalMoves(Board *board) {
	m_legalSquares.erase(m_legalSquares.begin(), m_legalSquares.begin()+m_legalSquares.size());
	for (Square *square : m_squaresInRange) {
		if (board->isMoveLegal(getSquare(), square)) {
			m_legalSquares.push_back(square);
		}
	}
}

size_t Piece::numberOfLegalMoves() {
	return m_legalSquares.size();
}

void Piece::printMoves() {
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	for (Square *square : m_legalSquares) {
		std::cout << file << rank << " ";
		std::cout << square->getFile() << square->getRank() << std::endl;
	}
}

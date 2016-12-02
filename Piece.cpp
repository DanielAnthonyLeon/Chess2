#include "Piece.hpp"
#include "Square.hpp"

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

void Piece::placeOnBoard(Square *square) {
	m_square = square;
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

int Piece::numberOfAttackers() {
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

void Piece::printMoves() {
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	for (Square *square : m_squaresInRange) {
		std::cout << file << rank << " ";
		std::cout << square->getFile() << square->getRank() << std::endl;
	}
}

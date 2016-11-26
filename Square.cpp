#include "Square.hpp"

Square::Square(char file, int rank, Piece *piece) :
m_file(file),
m_rank(rank),
m_piece(piece)
{
	
}

char Square::getFile() {
	return m_file;
}

char Square::getRank() {
	return m_rank;
}

Piece* Square::getPiece() {
	return m_piece;
}

SquareShade Square::getShade() {
	if ((m_file-'a') + m_rank % 2 == 0) {
		return LIGHT;
	}
	else {
		return DARK;
	}
}

std::string Square::symbol() {
	if (getPiece() == NULL) {
		return getShade() == LIGHT ? " " : "#";
	}
	else {
		return getPiece()->symbol();
	}
}

bool Square::isOccupied() {
	return m_piece != NULL;
}

bool Square::onBoard() {
	bool fileInBound = m_file >= 'a' && m_file <= 'h';
	bool rankInBound = m_rank >= 1 && m_rank <= 8;
	return fileInBound && rankInBound;
}

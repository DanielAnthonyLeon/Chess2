#include "Board.hpp"

Board::Board() {
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			m_board[8-rank][file-'a'] = new Square(file, rank);
		}
	}
}

Board::~Board() {
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			delete m_board[8-rank][file-'a'];
		}
	}
}

Square* Board::getSquare(char file, int rank) {
	if (file < 'a' || file > 'h' ||
			rank < 1 || rank > 8) {
		return NULL;
	}
	return m_board[8-rank][file-'a'];
}

#include "King.hpp"
#include "Board.hpp"

King::King(PieceColour colour) :
Piece(KING, colour)
{
	
}

std::string King::symbol() {
	return m_colour == WHITE ? "♔" : "♚";
}

void King::setSquaresInRange(Board *board) {
		// Empty the vector to start fresh
	Piece::setSquaresInRange(board);
	
	char file = getSquare()->getFile();
	int rank = getSquare()->getRank();
	
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
				// Actually a different square
			if (i != 0 || j != 0) {
				Square *s = board->getSquare(file+i, rank+j);
					// Square is on board
				if (s) {
						// Square is empty
					if (!s->isOccupied()) {
						m_squaresInRange.push_back(s);
					}
						// Piece on square is opposite colour
					else if (s->getPiece()->getColour() != m_colour) {
						m_squaresInRange.push_back(s);
					}
				}
			}
		}
	}
}

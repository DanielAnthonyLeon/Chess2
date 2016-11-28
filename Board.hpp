#ifndef Board_hpp
#define Board_hpp

#include "Square.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "King.hpp"

#include <string>
#include <iostream>

class Board {
private:
	Square* m_board[8][8];
public:
	Board();
	~Board();
	Square* getSquare(char file, int rank) const;
	Piece* createPiece(PieceType type, PieceColour colour);
	void placePiece(PieceType type, PieceColour colour, char file, int rank);
	void setUpPieces();
	void movePiece(Square *start, Square *destination);
	friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif /* Board_hpp */

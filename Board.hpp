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
	Piece* m_kings[2];
public:
	Board();
	~Board();
	Square* getSquare(char file, int rank) const;
	Piece* createPiece(PieceType type, PieceColour colour);
	void placePiece(PieceType type, PieceColour colour, char file, int rank);
	void setUpPieces();
	void movePiece(Square *start, Square *destination); // Possibly an illegal move
	void setPossibleMoves(); // Includes moves that put the king in check
	bool isMoveSemiLegal(Square *start, Square *destination); // Doesn't take being in check into account
	bool isInCheck(PieceColour colour);
	void printMoves();
	void printBoard(PieceColour colour);
};

#endif /* Board_hpp */

#ifndef Square_hpp
#define Square_hpp

#include "Piece.hpp"
#include "Board.hpp"
#include <stddef.h>
#include <string>

class Piece;
class Board;

enum SquareShade {
	LIGHT,
	DARK
};

class Square {
private:
	char m_file;
	int m_rank;
	Board *m_board;
	Piece *m_piece; // piece is independent or non-existant
public:
	Square(char file, int rank, Board *board, Piece *piece = NULL);
	char getFile();
	char getRank();
	Board* getBoard();
	Piece* getPiece();
	SquareShade getShade();
	std::string symbol();
	bool isOccupied();
	bool onBoard();
};

#endif /* Square_hpp */

#ifndef Square_hpp
#define Square_hpp

#include "Piece.hpp"
#include <stddef.h>
#include <string>

class Piece;

enum SquareShade {
	LIGHT,
	DARK
};

class Square {
private:
	char m_file;
	int m_rank;
	Piece *m_piece; // piece is independent or non-existant
public:
	Square(char file, int rank, Piece *piece = NULL);
	char getFile();
	char getRank();
	Piece* getPiece();
	SquareShade getShade();
	std::string symbol();
	bool isOccupied();
	bool onBoard();
};

#endif /* Square_hpp */

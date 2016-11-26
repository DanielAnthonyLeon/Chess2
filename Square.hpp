#ifndef Square_hpp
#define Square_hpp

#include "Piece.hpp"
#include <stddef.h>

class Piece;

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
	bool hasPiece();
	bool onBoard();
};

#endif /* Square_hpp */

#ifndef Square_hpp
#define Square_hpp

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
	Square(char file, int rank);
	char getFile();
	int getRank();
	Piece* getPiece();
	SquareShade getShade();
	std::string symbol();
	bool isOccupied();
	bool onBoard();
	void placePiece(Piece *piece);
	void removePiece();
};

#endif /* Square_hpp */

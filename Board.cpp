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
			Square *square = getSquare(file, rank);
			Piece *piece = square->getPiece();
			delete piece;
			delete square;
		}
	}
}

Square* Board::getSquare(char file, int rank) const {
	if (file < 'a' || file > 'h' ||
			rank < 1 || rank > 8) {
		return NULL;
	}
	return m_board[8-rank][file-'a'];
}

Piece* Board::createPiece(PieceType type, PieceColour colour) {
	switch (type) {
		case PAWN:
			return new Pawn(colour);
		case KNIGHT:
			return new Knight(colour);
		case BISHOP:
			return new Bishop(colour);
		case ROOK:
			return new Rook(colour);
		case QUEEN:
			return new Queen(colour);
		case KING:
			return new King(colour);
	}
}

void Board::placePiece(PieceType type, PieceColour colour, char file, int rank) {
		// Create a new piece
	Piece *piece = createPiece(type, colour);
	Square *square = getSquare(file, rank);
		// Place the piece on the square
	square->placePiece(piece);
	if (type == KING) {
		m_kings[colour] = piece;
	}
}

void Board::setUpPieces() {
		// Set up the pawns
	for (char file = 'a'; file <= 'h'; file++) {
			// White pawns
		placePiece(PAWN, WHITE, file, 2);
			// Black pawns
		placePiece(PAWN, BLACK, file, 7);
	}
	
		// Set up the knights
		// White knights
	placePiece(KNIGHT, WHITE, 'b', 1);
	placePiece(KNIGHT, WHITE, 'g', 1);
		// Black knights
	placePiece(KNIGHT, BLACK, 'b', 8);
	placePiece(KNIGHT, BLACK, 'g', 8);
	
		// Bishops
	placePiece(BISHOP, WHITE, 'c', 1);
	placePiece(BISHOP, WHITE, 'f', 1);
	placePiece(BISHOP, BLACK, 'c', 8);
	placePiece(BISHOP, BLACK, 'f', 8);
	
		// Rooks
	placePiece(ROOK, WHITE, 'a', 1);
	placePiece(ROOK, WHITE, 'h', 1);
	placePiece(ROOK, BLACK, 'a', 8);
	placePiece(ROOK, BLACK, 'h', 8);
	
		// Queens
	placePiece(QUEEN, WHITE, 'd', 1);
	placePiece(QUEEN, BLACK, 'd', 8);
	
		// Kings
	placePiece(KING, WHITE, 'e', 1);
	placePiece(KING, BLACK, 'e', 8);
}

void Board::movePiece(Square *start, Square *destination) {
	Piece *piece = start->getPiece();
	start->pickUpPiece();
	destination->placePiece(piece);
}

void Board::setPossibleMoves() {
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			Square *square = getSquare(file, rank);
			Piece *piece = square->getPiece();
				// Square is occupied
			if (piece) {
				// It is colour's turn
				piece->setSquaresInRange(this);
			}
		}
	}
}

bool Board::isMoveSemiLegal(Square *start, Square *destination) {
	Piece *piece = start->getPiece();
		// There actually is a piece on the start square
	if (piece) {
		return piece->isMoveSemiLegal(destination);
	}
	return false;
}

bool Board::isInCheck(PieceColour colour) {
	Piece *king = m_kings[colour];
	return (king->numberOfAttackers() > 0);
}

void Board::printMoves() {
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			Piece *piece = getSquare(file, rank)->getPiece();
			if (piece) {
				piece->printMoves();
			}
		}
	}
}

void Board::printBoard(PieceColour colour) {
	if (colour == WHITE) {
		for (int rank = 8; rank >= 1; rank--) {
			std::cout << rank;
			for (char file = 'a'; file <= 'h'; file++) {
				std::cout << ' ' << getSquare(file, rank)->symbol();
			}
			std::cout << std::endl;
		}
		std::cout << "  a b c d e f g h";
	}
	else {
		for (int rank = 1; rank <= 8; rank++) {
			std::cout << rank;
			for (char file = 'h'; file >= 'a'; file--) {
				std::cout << ' ' << getSquare(file, rank)->symbol();
			}
			std::cout << std::endl;
		}
		std::cout << "  h g f e d c b a";
	}
	std::cout << std::endl;
}

#include "Board.hpp"

Board::Board() {
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			m_board[8-rank][file-'a'] = new Square(file, rank);
		}
	}
}

Board::~Board() {
		// Destroy the board
	for (char file = 'a'; file <= 'h'; file++) {
		for (int rank = 1; rank <= 8; rank++) {
			Square *square = getSquare(file, rank);
			delete square;
		}
	}
		// Destroy the pieces
	for (Piece *whitePiece : m_pieces[WHITE]) {
		delete whitePiece;
	}
	for (Piece *blackPiece : m_pieces[BLACK]) {
		delete blackPiece;
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
	Piece *piece;
	switch (type) {
		case PAWN:
			piece = new Pawn(colour);
			break;
		case KNIGHT:
			piece = new Knight(colour);
			break;
		case BISHOP:
			piece = new Bishop(colour);
			break;
		case ROOK:
			piece = new Rook(colour);
			break;
		case QUEEN:
			piece = new Queen(colour);
			break;
		case KING:
			piece = new King(colour);
			break;
	}
	m_pieces[colour].push_back(piece);
	return piece;
}

void Board::placePiece(PieceType type, PieceColour colour, char file, int rank) {
		// Create a new piece
	Piece *piece = createPiece(type, colour);
	Square *square = getSquare(file, rank);
		// Place the piece on the square
	piece->place(square);
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
	if (start != destination) {
		Piece *piece = start->getPiece();
		piece->pickup();
		piece->place(destination);
	}
}

void Board::setPossibleMoves() {
	for (Piece *piece : m_pieces[WHITE]) {
		if (piece->isAlive()) {
			piece->setSquaresInRange(this);
		}
	}
	for (Piece *piece : m_pieces[BLACK]) {
		if (piece->isAlive()) {
			piece->setSquaresInRange(this);
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

bool Board::isMoveLegal(Square *start, Square *destination) {
	if (isMoveSemiLegal(start, destination)) {
		Piece *piece = start->getPiece();
		PieceColour colour = piece->getColour();
			// Move piece to see if it produces check
		movePiece(start, destination);
			// Set the moves for this new board
		setPossibleMoves();
			// Move does not put own king in check
		if (!isInCheck(colour)) {
				// Return the piece to its original square
			movePiece(destination, start);
				// Reset the moves
			setPossibleMoves();
			return true;
		}
		else {
			movePiece(destination, start);
			setPossibleMoves();
			return false;
		}
	}
	return false;
}

void Board::setLegalMoves() {
	setPossibleMoves();
	for (Piece *piece : m_pieces[WHITE]) {
		if (piece->isAlive()) {
			piece->setLegalMoves(this);
		}
	}
	for (Piece *piece : m_pieces[BLACK]) {
		if (piece->isAlive()) {
			piece->setLegalMoves(this);
		}
	}
}

	// Call this from within isInCheck test
bool Board::isCheckMate(PieceColour colour) {
	return m_kings[colour]->numberOfLegalMoves() == 0;
}

void Board::printMoves() {
	for (Piece *piece : m_pieces[WHITE]) {
		if (piece->isAlive()) {
			piece->printMoves();
		}
	}
	for (Piece *piece : m_pieces[BLACK]) {
		if (piece->isAlive()) {
			piece->printMoves();
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

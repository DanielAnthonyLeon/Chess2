#include "Game.hpp"

using namespace std;

Game::Game() :
m_turn(WHITE)
{
	m_board = new Board;
	m_board->setUpPieces();
}

bool Game::makeMove(char file1, int rank1, char file2, int rank2) {
	m_board->setPossibleMoves();
	
	Square *start = m_board->getSquare(file1, rank1);
	Square *destination = m_board->getSquare(file2, rank2);
	
		// Make sure squares are actually on board
	if (start && destination) {
		if (m_board->isMoveLegal(start, destination)) {
			m_board->movePiece(start, destination);
			return true;
		}
	}
	return false;
}

void Game::changeTurn() {
	m_turn == WHITE ? m_turn = BLACK : m_turn = WHITE;
}

void Game::playGame() {
	char file1;
	int rank1;
	char file2;
	int rank2;
	
	while (true) {
		m_board->setLegalMoves();
		m_board->printMoves();
		m_board->printBoard(m_turn);
		
		if (m_board->isInCheck(m_turn)) {
			if (m_board->isCheckMate(m_turn)) {
				cout << "Checkmate!\n";
				return;
			}
			cout << "Check!\n";
		}
		
		cin.clear();
		
			// Get the first square
		cin >> file1;
		
			// q to quit
		if (file1 == 'q') {
			break;
		}
		
		cin >> rank1;
		Square *start = m_board->getSquare(file1, rank1);
		if (start) {
			Piece *piece = start->getPiece();
			if (piece) {
				piece->printMoves();
			}
		}
		
			// Get the second square
		cin >> file2 >> rank2;
		
		if (makeMove(file1, rank1, file2, rank2)) {
			changeTurn();
		}
	}
}

void Game::playGameFromFile(std::string gameFile) {
	ifstream gameStream;
	gameStream.open(gameFile);
	
	char file1;
	int rank1;
	char file2;
	int rank2;
	
	char next;
	
	m_board->setPossibleMoves();
	m_board->printMoves();
	m_board->printBoard(m_turn);
	
	if (m_board->isInCheck(m_turn)) {
		cout << "Check!\n";
	}
	
	while (gameStream.good()) {
		gameStream >> file1;
		gameStream >> rank1;
		gameStream >> file2;
		gameStream >> rank2;
		
		makeMove(file1, rank1, file2, rank2);
		changeTurn();
		
		while (!(cin >> next));
	}
	
	gameStream.close();
}

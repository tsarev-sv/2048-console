#define _HAS_STD_BYTE_ 0
#define WIN32_LEAN_AND_MEAN
#define NOMINNAX
#include "Game.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#undef byte

using namespace std;


Game::Game() : gameOver(false), win(false), recordmanager("2048-record.txt") {}

void Game::handleInput() {
	if (_kbhit()) {
		char ch = _getch();
		bool moving = false;
		switch (ch) {
		case 'a': moving = board.moveLeft(); break;
		case 'd': moving = board.moveRight(); break;
		case 'w': moving = board.moveUp(); break;
		case 's': moving = board.moveDown(); break;
		case 'x': gameOver = true;
		}
		if (moving && !gameOver) {
			board.addRandomTitle();
			if (board.hasWon()) win = true;
			if (!board.canMove()) gameOver = true;
		}
	}
}

void Game::run() {
	while (!gameOver) {
		render.renderer(board);
		handleInput();
		Sleep(100);

		if (win) {
			render.renderer(board);
			recordmanager.saveRecord(board.getScore());
			cout << "\nYOU WIN! Score: " << board.getScore() << endl;
			gameOver = true;
			_getch();
			break;
		}
	}
	if (!win) {
		render.renderer(board);
		recordmanager.saveRecord(board.getScore());
		cout << "\nGAME OVER! Score: " << board.getScore() << endl;
		_getch();
	}
}

int Game::getScore() const { return recordmanager.LoadRecord(); }

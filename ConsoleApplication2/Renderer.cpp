#include "Renderer.h"
#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

void Renderer::renderer(const Board& board) {
	system("cls");

	cout << "=====================" << endl;
	cout << "        2048" << endl;
	cout << "Score: " << board.getScore() << endl;
	cout << "=====================" << endl;
	cout << "+------+------+------+------+" << endl;


	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 4; j++) {
			int val = board[i][j];
			if (val == 0) {
				cout << "      |";
			}
			else {
				cout << setw(6) << val << "|";
			}
		}

		cout << endl;

		if (i < 3) {
			cout << "+------+------+------+------+" << endl;
		}
	}
	cout << "+------+------+------+------+" << endl;
	cout << "=====================" << endl;
	cout << "move - WASD | X - exit" << endl;
}




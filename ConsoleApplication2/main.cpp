#include "Game.h"
#include<iostream>
#include<conio.h>

using namespace std;

void showMenu() {
	system("cls");
	cout << "=====================" << endl;
	cout << "        2048" << endl;
	cout << "=====================" << endl;
	cout << "1. Play" << endl;
	cout << "2. Top record" << endl;
	cout << "3. Exit" << endl;
	cout << "=====================" << endl;
}

void menuRecords() {
	Game game;
	system("cls");
	cout << "=====================" << endl;
	cout << "     TOP RECORD      " << endl;
	cout << "=====================" << endl;
	cout << "Score: " <<  game.getScore() << endl;
	cout << "=====================" << endl;
	_getch();
}

int main() {
	while (true) {
		showMenu();
		int choice = 0;
		while (!(cin >> choice) || choice < 1 || choice >3) {
			cout << "Enter a valid number (1,2,3): " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (choice == 3) {
			cout << "Goodbye!" << endl;
			break;
		}
		else if (choice == 2) {
			menuRecords();
		}
		else {
			Game game;
			game.run();
		}
	}
}
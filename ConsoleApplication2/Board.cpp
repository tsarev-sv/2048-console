#include "Board.h"
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<ctime>


using namespace std;

Board::Board() {
	srand(static_cast<unsigned>(time(nullptr)));
	reset();
}

void Board::reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i][j] = 0;
		}
	}
	score = 0;
	addRandomTitle();
	addRandomTitle();
}

void Board::transpose() {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			std::swap(grid[i][j], grid[j][i]);
		}
	}
}

void Board::reverse() {
	for (int i = 0; i < 4; i++) {
		std::reverse(grid[i], grid[i] + 4);
	}
}

bool Board::moveLeft() {
	bool anyMoved = false;
	for (int row = 0; row < 4; row++) {
		int temp[4] = { 0,0,0,0 };
		int idx = 0;
		for (int col = 0; col < 4; col++) {
			if (grid[row][col] != 0) {
				temp[idx++] = grid[row][col];
			}
		}

		for (int col = 0; col < 3; col++) {
			if (temp[col] != 0 && temp[col] == temp[col + 1]) {
				temp[col] *= 2;
				score += temp[col];
				temp[col + 1] = 0;
			}
		}

		int temp2[4] = { 0,0,0,0 };
		idx = 0;
		for (int col = 0; col < 4; col++) {
			if (temp[col] != 0) {
				temp2[idx++] = temp[col];
			}
		}

		for (int col = 0; col < 4; col++) {
			if (grid[row][col] != temp2[col]) {
				anyMoved = true;
			}
			grid[row][col] = temp2[col];
		}
	}
	return anyMoved;
}

bool Board::moveRight() {
	reverse();
	int result = moveLeft();
	reverse();
	return result;
}

bool Board::moveUp() {
	transpose();
	int result = moveLeft();
	transpose();
	return result;
}
bool Board::moveDown() {
	transpose();
	reverse();
	int result = moveLeft();
	reverse();
	transpose();
	return result;
}

bool Board::hasWon() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] == 2048) return true;
		}
	}
	return false;
}

bool Board::canMove() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] == 0) return true;
			else if (i < 3 && grid[i][j] == grid[i + 1][j]) return true;
			else if (j < 3 && grid[i][j] == grid[i][j + 1 ]) return true;
		}
	}
	return false;
}

void Board::addRandomTitle() {
	vector<pair<int, int>>EMPTY;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] == 0) {
				EMPTY.push_back({ i, j });
			}
		}
	}

	if (EMPTY.empty()) return;

	int idx = rand() % EMPTY.size();
	int val = (rand() % 10 < 9) ? 2 : 4;
	grid[EMPTY[idx].first][EMPTY[idx].second] = val;
}

int Board::getScore() const { return score; }
const int* Board::operator[](int i) const { return grid[i]; }



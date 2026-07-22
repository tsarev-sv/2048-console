#pragma once

class Board {
private:
	int grid[4][4];
	int score;

	void reset();
	void transpose();
	void reverse();
public:
	Board();

	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();

	bool hasWon() const;
	bool canMove() const;
	void addRandomTitle();

	int getScore() const;
	const int* operator[](int i) const;
};
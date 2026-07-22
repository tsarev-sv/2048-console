#pragma once
#include "Renderer.h"
#include "RecordManager.h"

class Game {
private:
	Board board;
	Renderer render;
	RecordManager recordmanager;
	bool gameOver;
	bool win;

	void handleInput();
public:
	Game();
	void run();
	int getScore() const;
};



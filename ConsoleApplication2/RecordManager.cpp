#include "RecordManager.h"
#include<fstream>

RecordManager::RecordManager(string filename) : file(filename){}

void RecordManager::saveRecord(int score, string player) {
	int OldRecord = LoadRecord();
	if (score > OldRecord) {
		ofstream out(file);
		if (out.is_open()) {
			out << player << " " << score;
		}
	}
}

int RecordManager::LoadRecord() const {
	ifstream input(file);
	int score = 0;
	string player;
	if (input.is_open()) {
		input >> player >> score;
	}
	return score;
}
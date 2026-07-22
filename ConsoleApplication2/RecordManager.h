#pragma once
#include<string>

using namespace std;


class RecordManager {
private:
	string file;
public:
	RecordManager(string filename);

	void saveRecord(int score = 0,string player = "Player");
	int LoadRecord() const;
};
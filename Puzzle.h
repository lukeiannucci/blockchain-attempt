#ifndef PUZZLE_H
#define PUZZLE_H
#include <string>

const size_t PUZZLE_DIFFICULTY = 4;

using namespace std;

class Puzzle {
public:
	Puzzle();
	string getProposedHash();
	void setProposedHash(string hash);
	string getPuzzle();

private:
	string proposedHash;
	string puzzle;
};
#endif


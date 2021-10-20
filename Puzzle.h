#ifndef PUZZLE_H
#define PUZZLE_H
#include <string>
#include <bitset>

const size_t PUZZLE_DIFFICULTY = 5;

using namespace std;

class Puzzle {
public:
	Puzzle();
	string getProposedHash();
	void setProposedHash(string hash);
	bitset<PUZZLE_DIFFICULTY> getPuzzle();

private:
	string proposedHash;
	bitset<PUZZLE_DIFFICULTY> puzzle;
};
#endif


#include "Puzzle.h"

Puzzle::Puzzle() {
	this->proposedHash = "";
}

string Puzzle::getProposedHash() {
	return this->proposedHash;
}

void Puzzle::setProposedHash(string hash) {
	this->proposedHash = hash;
}

bitset<PUZZLE_DIFFICULTY> Puzzle::getPuzzle() {
	return this->puzzle;
}

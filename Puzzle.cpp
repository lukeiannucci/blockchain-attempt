#include "Puzzle.h"

Puzzle::Puzzle() {
	this->proposedHash = "";
	this->puzzle = "";
	for (int i = 0; i < PUZZLE_DIFFICULTY; i++) {
		this->puzzle += "0";
	}
}

string Puzzle::getProposedHash() {
	return this->proposedHash;
}

void Puzzle::setProposedHash(string hash) {
	this->proposedHash = hash;
}

string Puzzle::getPuzzle() {
	return this->puzzle;
}

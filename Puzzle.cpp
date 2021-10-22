#include "Puzzle.h"

Puzzle::Puzzle() {
	this->puzzle = "";
	for (int i = 0; i < PUZZLE_DIFFICULTY; i++) {
		this->puzzle += "0";
	}
}

string Puzzle::getPuzzle() {
	return this->puzzle;
}

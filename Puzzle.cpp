#include "Puzzle.h"

Puzzle::Puzzle() {
	this->solved = false;
	generate();
}

void Puzzle::generate() {
	//todo
}

bool Puzzle::getSolved() {
	return this->solved;
}

void Puzzle::setSolved(bool solved) {
	this->solved = solved;
}

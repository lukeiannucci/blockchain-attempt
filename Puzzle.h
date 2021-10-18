#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
public:
	Puzzle();
	void generate();
	bool getSolved();
	void setSolved(bool solved);

private:
	bool solved;
};
#endif


#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <map>
#include "Block.h"

using namespace std;

class Blockchain {
public:
	void addBlock(Block* block);
	void displayBlockchain();

	Blockchain();

private:
	//todo is this really a vector?
	vector<Block> blockchain;
};
#endif
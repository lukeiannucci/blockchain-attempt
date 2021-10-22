#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <map>
#include "Block.h"

using namespace std;

class Blockchain {
public:
	void addBlock();
	void displayBlockchain();
	void proposeBlock(Block* block);
	Block* getProposedBlock();
	Blockchain();
	bool getBlockAccepted();

private:
	Block* latestProposedBlock;
	bool blockAccepted;
	//todo is this really a vector?
	vector<Block> blockchain;
};
#endif
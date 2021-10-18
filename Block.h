#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <map>
#include "Transaction.h"

using namespace std;

class Block {
public:
	Block();
	unsigned int getPreviousHash();
	void setPreviousHash(unsigned int previousHash);
	unsigned int getCurrentHash();
	void setCurrentHash(unsigned int currentHash);
	void addTransactionsToBlock(Transaction* transactions);

private:
	unsigned int previousHash;
	unsigned int currentHash;
	map<unsigned int, Transaction> transactions;
};
#endif
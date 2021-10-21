#ifndef MINER_h
#define MINER_H

#include "TransactionPool.h"
#include "Puzzle.h"
#include "Block.h"
#include "Sha256.h"
#include <algorithm>
#include <mutex>

const unsigned int NUM_TRANSACTIONS_PER_BLOCK = 2;

class Miner {
public:
	Miner();
	void mine(Puzzle* puzzle, TransactionPool* transactionPool, mutex * mtx);
	bool verifyHash(string hash, Puzzle* puzzle);
	Transaction* getHighestTransactionFees();
private:
	void setHighestTransactionsFees(TransactionPool* transactionPool);
	string createHash();
	string getTransactionInput();
	string generateRandomString(size_t length);
	Transaction* highestTransactionFees;
};
#endif // !MINER_h

#ifndef MINER_h
#define MINER_H

#include "TransactionPool.h"
#include "Puzzle.h"
#include <string>

const unsigned int NUM_TRANSACTIONS_PER_BLOCK = 2;

class Miner {
public:
	Miner(TransactionPool* transactionPool, Puzzle * puzzle);
	void mine();
	bool verifyHash(Transaction* transactions, string input);

private:
	Transaction** getHighestTransactionsFees();
	TransactionPool* transactionPool;
	Puzzle* puzzle;
};
#endif // !MINER_h

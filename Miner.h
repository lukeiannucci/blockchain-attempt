#ifndef MINER_h
#define MINER_H

#include "TransactionPool.h"
#include "Blockchain.h"
#include "Puzzle.h"
#include "Block.h"
#include <algorithm>
#include <mutex>
#include <atomic>
#include <chrono>
#include <thread>

const unsigned int MINERS_TO_SPAWN = 10;
using namespace std::this_thread;
using namespace std::chrono;

class Miner {
public:
	Miner();
	void mine(Puzzle* puzzle, TransactionPool* transactionPool, mutex * mtx, Blockchain* blockChain, atomic_int * confirmations);
	bool verifyHash(string hash, Puzzle* puzzle);
	Transaction* getHighestTransactionFees();
private:
	bool setHighestTransactionsFees(TransactionPool* transactionPool);
	string createHash(string input);
	string getTransactionInput(Transaction* transactions);
	string generateRandomString(size_t length);
	Transaction* highestTransactionFees;
	bool verified;
};
#endif // !MINER_h

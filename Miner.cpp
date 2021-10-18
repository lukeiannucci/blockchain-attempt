#include "Miner.h"
#include <algorithm>

Miner::Miner(TransactionPool* transactionPool, Puzzle * puzzle) {
	this->transactionPool = transactionPool;
	this->puzzle = puzzle;
}

//trying to make bread $$$$$ find highest txn fees
Transaction** Miner::getHighestTransactionsFees() {
	Transaction** transactions = new Transaction*[NUM_TRANSACTIONS_PER_BLOCK];
	//todo - should have this sorted, maybe insertion sort in transaction pool
	auto transactionsPending = this->transactionPool->getTransactionsPending();
	int maxFeeOne = 0;
	int maxFeeTwo = 0;
	for (int i = 0; i < MAX_TRANSACTIONS; i++) {
		auto transactionPending = transactionsPending[i];
		if (transactionPending != nullptr) {
			auto gasFee = transactionPending->getGasFee();
			if (maxFeeOne < gasFee) {
				if (maxFeeTwo < maxFeeOne && maxFeeOne > 0) {
					maxFeeTwo = maxFeeOne;
					transactions[1] = transactions[0];
				}
				maxFeeOne = gasFee;
				transactions[0] = transactionPending;
			} else if (maxFeeTwo < gasFee) {
				maxFeeTwo = gasFee;
				transactions[1] = transactionPending;
			}
		}
	}
	return transactions;
}

void Miner::mine() {
	auto highestTransactionFees = getHighestTransactionsFees();
	auto temp = highestTransactionFees[0];
	auto temp2 = highestTransactionFees[1];

	//todo compute input against transactions to solve puzzle
	
	delete[] highestTransactionFees;
	return;
}

bool Miner::verifyHash(Transaction* transactions, string input) {
	return false;
}

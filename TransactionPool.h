#ifndef TRANSACTIONPOOL_H
#define TRANSACTIONPOOL_H

#include "Transaction.h"
#include <unordered_set>

const unsigned int MAX_TRANSACTIONS = 6;

class TransactionPool {
public:
	TransactionPool();
	unordered_set<Transaction, Transaction> getTransactionsPending();
	void remove(Transaction transaction);
private:
	unordered_set<Transaction, Transaction> transactionsPending;
};
#endif // !TRANSCATIONPOOL_H


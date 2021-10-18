#ifndef TRANSACTIONPOOL_H
#define TRANSACTIONPOOL_H

#include "Transaction.h"
#include <deque>

const unsigned int MAX_TRANSACTIONS = 6;

class TransactionPool {
public:
	TransactionPool();
	Transaction** getTransactionsPending();
private:
	Transaction** transactionsPending;
	void createTransaction(unsigned int fromAddress, unsigned int toAddress, unsigned int amount, unsigned int gasFee, unsigned int index);
};
#endif // !TRANSCATIONPOOL_H


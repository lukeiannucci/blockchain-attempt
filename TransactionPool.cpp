#include "TransactionPool.h"

TransactionPool::TransactionPool()
{
	this->transactionsPending = new Transaction * [MAX_TRANSACTIONS];
	createTransaction(0x1, 0x2, 10, 7, 0);
	createTransaction(0x2, 0x3, 5, 1, 1);
	createTransaction(0x5, 0x1, 3, 2, 2);
	createTransaction(0x11, 0x3, 2, 1,3);
	createTransaction(0x7, 0x5, 10, 7, 4);
	createTransaction(0x8, 0x10, 10, 5, 5);
	/*createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);*/
}

Transaction** TransactionPool::getTransactionsPending() {
	return this->transactionsPending;
}

void TransactionPool::createTransaction(unsigned int fromAddress, unsigned int toAddress, unsigned int amount, unsigned int gasFee, unsigned int index) {
	this->transactionsPending[index] = new Transaction(fromAddress, toAddress, amount, gasFee);
}

#include "TransactionPool.h"

TransactionPool::TransactionPool()
{
	this->transactionsPending.insert(Transaction(1, 2, 10, 1));
	this->transactionsPending.insert(Transaction(2, 3, 5, 7));
	this->transactionsPending.insert(Transaction(0x5, 0x1, 3, 2));
	this->transactionsPending.insert(Transaction(0x11, 0x3, 2, 1));
	this->transactionsPending.insert(Transaction(0x8, 0x10, 10, 8));
	this->transactionsPending.insert(Transaction(10, 3, 3, 5));
	/*createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);
	createTransaction(1, 2, 3, 2, 0);*/
}

unordered_set<Transaction, Transaction> TransactionPool::getTransactionsPending() {
	return this->transactionsPending;
}

void TransactionPool::remove(Transaction transaction){
	this->transactionsPending.erase(transaction);
}

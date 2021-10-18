#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
using namespace std;

class Transaction {
public:
	Transaction();
	Transaction(unsigned int from, unsigned int to, unsigned int amount, unsigned int gasFee);
	//getters
	unsigned int getTransactionHash();
	unsigned int getFromAddress();
	unsigned int getToAddress();
	unsigned int getAmount();
	unsigned int getGasFee();

	//setter
	void setTransactionHash(unsigned int transactionHash);
	void setFromAddress(unsigned int fromAddress);
	void setToAddress(unsigned int toAddress);
	void setAmount(unsigned int amount);
	void setGasFee(unsigned int gasFee);
private:
	unsigned int transactionHash;
	unsigned int fromAddress;
	unsigned int toAddress;
	unsigned int amount;
	unsigned int gasFee;
};
#endif

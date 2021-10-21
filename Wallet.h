#ifndef WALLET_H
#define WALLET_H

#include <memory>
#include <vector>
#include <string>
#include "Transaction.h"

using namespace std;

const unsigned int MAX_WALLET_NAME_LENGTH = 20U;

class Wallet {
public:
	Wallet();
	Wallet(unsigned int address, unsigned int coins, string name, Transaction* transactionHistory, unsigned int historySize);
	~Wallet();
	//getters
	unsigned int getAddress();
	unsigned int getCoins();
	string getName() const;
	vector<Transaction> getTransactionHistory();

	//setter
	void setAddress(unsigned int address);
	void setCoins(unsigned int coins);
	void setName(char* name);
	void addTransactionToHistory(Transaction transaction);
private:
	unsigned int address;
	unsigned int coins;
	string name;
	vector<Transaction> transactionHistory;

	void applyTransaction(Transaction transaction);
};

#endif // !WALLET_H

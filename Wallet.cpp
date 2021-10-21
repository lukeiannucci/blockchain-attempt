#include "Wallet.h"

Wallet::Wallet() {
	this->address = 0x0;
	this->coins = 0;
	char* name = new char[MAX_WALLET_NAME_LENGTH];
	for (int i = 0; i < MAX_WALLET_NAME_LENGTH; i++) {
		name[i] = '/0';
	}
}

Wallet::Wallet(unsigned int address, unsigned int coins, string name, Transaction* transactionHistory, unsigned int historySize) {
	this->address = address;
	this->coins = coins;
	this->name = name;
	for (int i = 0; i < historySize; i++) {
		this->transactionHistory.push_back(transactionHistory[i]);
	}
}

Wallet::~Wallet() {
	this->transactionHistory.clear();
}

#pragma region GETTERS
unsigned int Wallet::getAddress() {
	return this->address;
}

unsigned int Wallet::getCoins() {
	return this->coins;
}

string Wallet::getName() const {
	return this->name;
}

vector<Transaction> Wallet::getTransactionHistory() {
	return this->transactionHistory;
}
#pragma endregion

#pragma region SETTERS
void Wallet::setAddress(unsigned int address) {
	this->address = address;
}

void Wallet::setCoins(unsigned int coins) {
	this->coins = coins;
}

void Wallet::setName(char* name) {
	this->name = name;
}
#pragma endregion


void Wallet::addTransactionToHistory(Transaction transaction) {
	this->applyTransaction(transaction);
	this->transactionHistory.push_back(transaction);
}

void Wallet::applyTransaction(Transaction transaction) {
	auto amount = transaction.getAmount();
	
	if (transaction.getFromAddress() == this->address) {
		auto fee = transaction.getGasFee();
		this->coins -= (amount + fee);
	}
	else {
		this->coins += amount;
	}
	//todo miner logic here maybe
}

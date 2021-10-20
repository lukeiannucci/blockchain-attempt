#include "Transaction.h"

Transaction::Transaction() {
	this->transactionHash = 0;
	this->fromAddress = 0;
	this->toAddress = 0;
	this->amount = 0;
	this->gasFee = 0;
}

Transaction::Transaction(unsigned int from, unsigned int to, unsigned int amount, unsigned int gasFee) {
	this->transactionHash = 0x0;
	this->fromAddress = from;
	this->toAddress = to;
	this->amount = amount;
	this->gasFee = gasFee;
}

#pragma region GETTERS
unsigned int Transaction::getTransactionHash() {
	return this->transactionHash;
}

unsigned int Transaction::getFromAddress() {
	return this->fromAddress;
}

unsigned int Transaction::getToAddress() {
	return this->toAddress;
}

unsigned int Transaction::getAmount() {
	return this->amount;
}

unsigned int Transaction::getGasFee() {
	return this->gasFee;
}
#pragma endregion

#pragma region SETTERS
void Transaction::setTransactionHash(unsigned int transactionHash) {
	this->transactionHash = transactionHash;
}

void Transaction::setFromAddress(unsigned int fromAddress) {
	this->fromAddress = fromAddress;
}

void Transaction::setToAddress(unsigned int toAddress) {
	this->toAddress = toAddress;
}

void Transaction::setAmount(unsigned int amount) {
	this->amount = amount;
}

void Transaction::setGasFee(unsigned int gasFee) {
	this->gasFee = gasFee;
}
#pragma endregion

string Transaction::toString() {
	return to_string(this->getAmount()) + " " + to_string(this->getFromAddress()) + " " + to_string(this->getToAddress()) + " " + to_string(this->getGasFee());
}
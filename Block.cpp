#include "Block.h"

Block::Block() {
	this->currentHash = 0;
	this->previousHash = 0;
}

unsigned int Block::getCurrentHash() {
	return this->currentHash;
}

void Block::setCurrentHash(unsigned int currentHash) {
	this->currentHash = currentHash;
}

unsigned int Block::getPreviousHash() {
	return this->previousHash;
}

void Block::setPreviousHash(unsigned int previousHash) {
	this->previousHash = previousHash;
}

void Block::addTransactionsToBlock(Transaction* transactions) {
	//todo
}
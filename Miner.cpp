#include "Miner.h"


Miner::Miner() {
	this->highestTransactionFees = new Transaction[NUM_TRANSACTIONS_PER_BLOCK];
}

//trying to make bread $$$$$ find highest txn fees
void Miner::setHighestTransactionsFees(TransactionPool* transactionPool) {
	//leave unsorted not a standard queue more of priority queue based on gas fee
	//super inefficient
	auto transactionsPending = transactionPool->getTransactionsPending();
	unsigned int maxFeeOne = 0;
	unsigned int maxFeeTwo = 0;
	for (int i = 0; i < MAX_TRANSACTIONS; i++) {
		auto transactionPending = transactionsPending[i];
		auto gasFee = transactionPending.getGasFee();
		if (maxFeeOne < gasFee) {
			if (maxFeeTwo < maxFeeOne && maxFeeOne > 0) {
				maxFeeTwo = maxFeeOne;
				this->highestTransactionFees[1] = this->highestTransactionFees[0];
			}
			maxFeeOne = gasFee;
			this->highestTransactionFees[0] = transactionPending;
		} else if (maxFeeTwo < gasFee) {
			maxFeeTwo = gasFee;
			this->highestTransactionFees[1] = transactionPending;
		}
	}
}

Transaction* Miner::getHighestTransactionFees() {
	return this->highestTransactionFees;
}

void Miner::mine(Puzzle* puzzle, TransactionPool* transactionPool, mutex * mtx) {
	setHighestTransactionsFees(transactionPool);
	do {
		string hash = this->createHash();
		bool wonChallenge = this->verifyHash(hash, puzzle);
		//reward first miner only by locking critical section
		(*mtx).lock();
		if (wonChallenge && puzzle->getProposedHash().empty()) {
			puzzle->setProposedHash(hash);
		}
		(*mtx).unlock();
	} while (puzzle->getProposedHash().empty());
	int i = 0;
}

string Miner::createHash() {
	string input = this->getTransactionInput();
	input += this->generateRandomString(10);

	return sha256(input);
}

string Miner::getTransactionInput() {
	string transactionString;
	for (int i = 0; i < MAX_TRANSACTIONS_PER_BLOCK; i++) {
		transactionString += this->highestTransactionFees[i].toString() + "|";
	}
	return transactionString;
}

bool Miner::verifyHash(string hash, Puzzle* puzzle) {
	return puzzle->getPuzzle() == hash.substr(0, PUZZLE_DIFFICULTY);
}

string Miner::generateRandomString(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

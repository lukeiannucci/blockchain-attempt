#include "Miner.h"


Miner::Miner() {
	this->highestTransactionFees = new Transaction[MAX_TRANSACTIONS_PER_BLOCK];
	this->verified = false;
}

//trying to make bread $$$$$ find highest txn fees
void Miner::setHighestTransactionsFees(TransactionPool* transactionPool) {
	//leave unsorted not a standard queue more of priority queue based on gas fee
	//super inefficient
	auto transactionsPending = transactionPool->getTransactionsPending();
	unsigned int maxFeeOne = 0;
	unsigned int maxFeeTwo = 0;
	for (int i = 0; i < MAX_TRANSACTIONS; i++) {
		int j = 0;
		auto transactionPending = transactionsPending[i];
		auto gasFee = transactionPending.getGasFee();
		if (maxFeeOne < gasFee) {
			if (maxFeeTwo < maxFeeOne && maxFeeOne > 0) {
				maxFeeTwo = maxFeeOne;
				this->highestTransactionFees[1] = this->highestTransactionFees[0];
			}
			maxFeeOne = gasFee;
			this->highestTransactionFees[0] = transactionPending;
		}
		else if (maxFeeTwo < gasFee) {
			maxFeeTwo = gasFee;
			this->highestTransactionFees[1] = transactionPending;
		}
	}
}

Transaction* Miner::getHighestTransactionFees() {
	return this->highestTransactionFees;
}

void Miner::mine(Puzzle* puzzle, TransactionPool* transactionPool, mutex * mtx, Blockchain * blockChain, atomic_int * confirmations) {
	setHighestTransactionsFees(transactionPool);
	do {
		string input = this->getTransactionInput(this->highestTransactionFees);
		string randomString = this->generateRandomString(10);
		string hash = this->createHash(input + randomString);
		bool wonChallenge = this->verifyHash(hash, puzzle);
		//reward first miner only by locking critical section
		(*mtx).lock();
		if (wonChallenge && blockChain->getProposedBlock() == nullptr) {
			this->verified = true;
			blockChain->proposeBlock(new Block(hash, randomString, this->highestTransactionFees));
			++(*confirmations);
		}
		(*mtx).unlock();
		if (blockChain->getProposedBlock() != nullptr && !this->verified) {
			//it will run a verification whether hash is good or bad
			this->verified = true;
			string transactionsString = this->getTransactionInput(blockChain->getProposedBlock()->getProposedTransactions());
			string verifiedHash = this->createHash(transactionsString + blockChain->getProposedBlock()->getInput());
			bool confirmed = this->verifyHash(verifiedHash, puzzle);
			if (confirmed) {
				++(*confirmations);
			}
		}
		(*mtx).lock();
		if (confirmations->load() > (MINERS_TO_SPAWN / 2) && !blockChain->getBlockAccepted()) {
			blockChain->addBlock();
		}
		(*mtx).unlock();
		if (blockChain->getBlockAccepted()) {
			break;
		}
	} while (true);

	delete[] this->highestTransactionFees;
	this->highestTransactionFees = new Transaction[MAX_TRANSACTIONS_PER_BLOCK];
	this->verified = false;
	//wait for other miners
	sleep_for(milliseconds(5000));
	//mine until no more transactions in pool
	mine(puzzle, transactionPool, mtx, blockChain, confirmations);
	
	int i = 0;
}

string Miner::createHash(string input) {
	return sha256(input);
}

string Miner::getTransactionInput(Transaction* transactions) {
	string transactionString;
	for (int i = 0; i < MAX_TRANSACTIONS_PER_BLOCK; i++) {
		transactionString += transactions[i].toString() + "|";
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

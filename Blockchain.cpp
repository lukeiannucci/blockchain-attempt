#include "Blockchain.h"

Blockchain::Blockchain() {
	this->latestProposedBlock = nullptr;
	this->blockAccepted = false;
}

void Blockchain::addBlock() {
	if (!this->blockchain.empty()) {
		auto lastBlock = this->blockchain.back();
		this->latestProposedBlock->setPreviousHash(lastBlock.getCurrentHash());
	}

	this->latestProposedBlock->addTransactionsToBlock();
	
	this->blockchain.push_back(*this->latestProposedBlock);
	this->blockAccepted = true;
}

bool Blockchain::getBlockAccepted() {
	return this->blockAccepted;
}

void Blockchain::setBlockAccepted(bool blockAccepted) {
	this->blockAccepted = false;
}

void Blockchain::displayBlockchain() {
	cout << "Successfully mined block with hash: " + (this->blockchain.end()-1)->getCurrentHash() << endl;
}

void Blockchain::proposeBlock(Block* block) {
	this->latestProposedBlock = block;
}

Block* Blockchain::getProposedBlock()
{
	return this->latestProposedBlock;
}

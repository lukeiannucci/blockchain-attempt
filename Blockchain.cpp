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
	
	this->blockchain.push_back(*this->latestProposedBlock);
	
	//delete latestProposedBlock;
	//latestProposedBlock = nullptr;
	this->blockAccepted = true;
}

bool Blockchain::getBlockAccepted() {
	return this->blockAccepted;
}

void Blockchain::setBlockAccepted(bool blockAccepted) {
	this->blockAccepted = false;
}

void Blockchain::displayBlockchain() {
	//todo
}

void Blockchain::proposeBlock(Block* block) {
	this->latestProposedBlock = block;
}

Block* Blockchain::getProposedBlock()
{
	return this->latestProposedBlock;
}

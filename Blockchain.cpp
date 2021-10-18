#include "Blockchain.h"

Blockchain::Blockchain() {

}

void Blockchain::addBlock(Block * block) {
	this->blockchain.push_back(*block);
}

void Blockchain::displayBlockchain() {
	//todo
}
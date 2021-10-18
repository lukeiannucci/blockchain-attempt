#include "WalletManager.h"

WalletManager::WalletManager() {
	for (int i = 0; i < GENERATE_WALLETS_VALUE; i++) {
		string name = "wallet: " + to_string(i);
		Wallet* wallet = new Wallet(i+1, STARTING_COIN_VALUE, name, NULL, 0);
		this->wallets.insert(pair<unsigned int, Wallet*>(wallet->getAddress(), wallet));
	}
}

WalletManager::~WalletManager() {
	for (auto wallet : this->wallets) {
		delete wallet.second;
	}

	this->wallets.clear();
}

Wallet * WalletManager::findWalletByAddress(unsigned int address) {
	auto walletIt = this->wallets.find(address);
	if (walletIt != this->wallets.end()) {
		return walletIt->second;
	}
	return nullptr;
}
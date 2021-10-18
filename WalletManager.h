#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include "Wallet.h"
#include <map>
using namespace std;

const unsigned short int GENERATE_WALLETS_VALUE = 10;
const unsigned short int STARTING_COIN_VALUE = 50;

class WalletManager {
public:
	WalletManager();
	~WalletManager();

	Wallet * findWalletByAddress(unsigned int address);

private:
	map<unsigned int, Wallet*> wallets;
};
#endif // !WALLETMANAGER_H


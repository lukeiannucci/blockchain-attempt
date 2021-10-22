// PoW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Miner.h"
#include <thread>

void walletTest() {
    /*char name[] = "lukes wallet";
    char name2[] = "toms wallet";
    Wallet lukesWallet(0x1, 10, name, NULL, 0);
    Wallet tomsWallet(0x2, 10, name2, NULL, 0);
    Transaction transaction(0x1, 0x2, 2, 1);
    lukesWallet.addTransactionToHistory(transaction);
    tomsWallet.addTransactionToHistory(transaction);
    WalletManager walletManager;
    auto temp1 = walletManager.findWalletByAddress(1);
    auto temp2 = walletManager.findWalletByAddress(10);
    int i = 0;*/
}



int main()
{
    //walletTest();
    TransactionPool transactionPool;
    Puzzle puzzle;
    thread threads[MINERS_TO_SPAWN];
    Miner miners[MINERS_TO_SPAWN];
    string hash;
    mutex mtx;
    Blockchain blockChain;
    std::atomic_int confirmations{0};

    for (int i = 0; i < MINERS_TO_SPAWN; i++) {
        threads[i] = thread(&Miner::mine, miners[i], &puzzle, &transactionPool, &mtx, &blockChain, &confirmations);
    }

    for (int i = 0; i < MINERS_TO_SPAWN; i++) {
        threads[i].join();
    }

    
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

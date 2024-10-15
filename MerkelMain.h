#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
using namespace std;

class MerkelMain
{
    public:
    
    MerkelMain();
    /** Call this to start simulation */
    void init();

    private:

    void loadOrderBook();
    void printMenu();
    int getUserOption();
    void printHelp();
    void printStats();
    void printOffer();
    void printBid();
    void printWallet();
    void goNext();
    void processUserOption(int userOption);

    std::vector<OrderBookEntry> orders;
 
};
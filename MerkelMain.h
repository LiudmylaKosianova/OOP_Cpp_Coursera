#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "CSVReader.h"

using namespace std;

class MerkelMain
{
    public:
    
    MerkelMain();
    /** Call this to start simulation */
    void init();

    private:

     
    void printMenu();
    int getUserOption();
    void printHelp();
    void printStats();
    void printOffer();
    void printBid();
    void printWallet();
    void goNext();
    void processUserOption(int userOption);

    OrderBook orderBook{"20200317.csv"};
    string currentTime;
 
};
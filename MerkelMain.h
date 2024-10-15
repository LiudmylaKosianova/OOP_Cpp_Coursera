#include <iostream>
#include <string>
using namespace std;

class MerkelMain
{
    public:
    
    MerkelMain();

    void init();

    void printMenu();
    int getUserOption();
    void printHelp();
    void printStats();
    void printOffer();
    void printBid();
    void printWallet();
    void goNext();
    void processUserOption(int userOption);
 
};
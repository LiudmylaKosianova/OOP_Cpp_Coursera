#include "MerkelMain.h"

    
MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    loadOrderBook();
    int input = 0;

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);

    }

}

void MerkelMain::loadOrderBook()
{
        
    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.02187307,
                                    3.467434});

    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.02187305,
                                    6.85567013});
}

void MerkelMain::printMenu()
{ 
        cout << " " << endl;
        cout << "=======MENU=======" << endl;
        cout << "1: Print help" << endl;
        cout << "2: Print exchange stats" << endl;
        cout << "3: Place an offer" << endl;
        cout << "4: Place a bid" << endl;
        cout << "5: Print wallet" << endl;
        cout << "6: Continue" << endl;
        cout << "==================" << endl;
}

int MerkelMain::getUserOption()
{
    //get user option
    cout << "" << endl;
    cout << "Type in 1-6: ";
    int userOption;
    cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    cout << "Follow the instructions. Your goal is to make money." << endl;
}

void MerkelMain::printStats()
{
    cout << "Your stats are empty." << endl;
    cout << "Order Book contains: " << orders.size() << " entries" << endl;
}

void MerkelMain::printOffer()
{
    cout << "Specify what you want to sell." << endl;
}

void MerkelMain::printBid()
{
    cout << "Specify what you want to buy." << endl;
}

void MerkelMain::printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void MerkelMain::goNext()
{
    cout << "Moving on." << endl;
}

void MerkelMain::processUserOption(int userOption)
{
    //check user input and take actions
    switch(userOption)
    {
        case 1:
        printHelp();
        break;
        case 2:
        printStats();
        break;
        case 3:
        printOffer();
        break;
        case 4:
        printBid();
        break;
        case 5:
        printWallet();
        break;
        case 6:
        goNext();
        break;
        default:
        cout << "Bad input. Please, choose the number 1-6." << endl;
        break;
    }
}

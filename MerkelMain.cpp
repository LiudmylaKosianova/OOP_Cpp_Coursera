#include "MerkelMain.h"


    
MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
     
    int input = 0;

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);

    }

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
   
    for(std::string const& p : orderBook.getKnownProduct())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, "2020/03/17 17:01:24.884492");
        std::cout << "Asks seen: " << entries.size() << std::endl; 
        std::cout << "Max ask price: " << OrderBook::getHighPrice(entries) << std::endl;
    }

    
    // cout << "Order Book contains: " << orders.size() << " entries" << endl;
    // unsigned int ask = 0;
    // unsigned int bid = 0;
    // for(OrderBookEntry& e : orders)
    // {
    //     if(e.orderType == OrderBookType::ask) ++ask;
    //     if(e.orderType == OrderBookType::bid) ++bid;
    // }
    // cout << "Number of bids: " << bid << endl;
    // cout << "Number of asks: " << ask << endl;
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
    cout << "" << endl;
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

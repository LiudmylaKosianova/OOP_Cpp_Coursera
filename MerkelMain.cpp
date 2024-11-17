#include "MerkelMain.h"


    
MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
     
    int input = 0;
    currentTime = orderBook.getEarliestTime();

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
        cout << "Current time is: " << currentTime << endl;
}

int MerkelMain::getUserOption()
{
    //get user option
    std::cout << "" << endl;
    std::cout << "Type in 1-6: ";

    int userOption = 0;
    std::string line;
    std::getline(std::cin, line);
    try
    {
    userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
         
    }

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
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl; 
        std::cout << "Max ask price: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask price: " << OrderBook::getLowPrice(entries) << std::endl;
        std::cout << "Total volume (" << p << "): " << OrderBook::getAmount(entries) << std::endl;
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

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - specify what you want to sell in the format \"product, price, amount\" eg. ETH/BTC, 200, 0.05 " << std::endl;
    
    std::string input;     
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if(tokens.size() != 3)
        {
            std::cout << "Bad input." << std::endl;
        }
    else
        {
            try
                {
                    OrderBookEntry obe = CSVReader::stringsToOBE(currentTime, 
                                                            tokens[0], 
                                                            OrderBookType::ask,
                                                            tokens[1], 
                                                            tokens[2]);
                    
                    orderBook.insertOrder(obe);   
                }
            catch(const std::exception& e)
                {
                    std::cout << "MerkelMain::enterAsk bad input!" << std::endl;
                }
        }

    std::cout << "You entered: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    cout << "Make a bid - specify what you want to buy." << endl;
}

void MerkelMain::printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void MerkelMain::goNext()
{
    cout << "Moving on to the next time frame..." << endl;
    currentTime = orderBook.getNextTime(currentTime);   

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
        enterAsk();
        break;
        case 4:
        enterBid();
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

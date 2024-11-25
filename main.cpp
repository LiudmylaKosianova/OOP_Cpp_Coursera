#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"





int main()
{
    // MerkelMain app{};
    // app.init();

    Wallet wallet;

    // wallet.insertCurrency("BTC", 5);
    // std::cout << wallet.toString() << std::endl;
    // wallet.insertCurrency("BTC", 5);
    // std::cout << wallet.toString() << std::endl;
    // wallet.insertCurrency("USD", 1000);    
    // std::cout << wallet.toString() << std::endl;
    // wallet.insertCurrency("ETR", -5);

    // std::cout << "Removing USD amount 305000..." << std::endl;    
    // wallet.removeCurrency("USD", 305000);
    // std::cout << wallet.toString() << std::endl;
    // std::cout << "Removing USD amount 1000..." << std::endl;    
    // wallet.removeCurrency("USD", 1000);
    // std::cout << wallet.toString() << std::endl;
    // std::cout << "Removing BTC amount -1" << std::endl;
    // wallet.removeCurrency("BTC", -1);
    // std::cout << wallet.toString() << std::endl;

    wallet.insertCurrency("USD", 1000);
    wallet.insertCurrency("BTC", 5);
    std::cout << wallet.toString() << std::endl;
    std::cout << "Cecking if the wallet contains BTC amount 10..." << std::endl;
    std::cout << wallet.constainsCurrency("BTC", 10) << std::endl;
    std::cout << "Cecking if the wallet contains BTC amount 4..." << std::endl;
    std::cout << wallet.constainsCurrency("BTC", 5) << std::endl;  

    return 0;
}
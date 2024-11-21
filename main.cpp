#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"





int main()
{
    MerkelMain app{};
    app.init();

    // Wallet wallet;
    // wallet.insertCurrency("BTC", 1);
    // wallet.insertCurrency("BTC", 11);
    // wallet.insertCurrency("USD", 10000);
    
    // std::cout << wallet.toString() << std::endl;
    // wallet.removeCurrency("USD", 1000);

    // std::cout << wallet.toString() << std::endl;


       

    return 0;
}
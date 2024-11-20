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
    wallet.insertCurrency("BTC", 1);
    std::cout << "Wallet contains 11 BTC " << wallet.constainsCurrency("BTC", 11) << std::endl;
    std::cout << wallet.toString() << std::endl;
    wallet.insertCurrency("BTC", 11);
    std::cout << "Wallet contains 11 BTC " << wallet.constainsCurrency("BTC", 11) << std::endl;

       

    return 0;
}
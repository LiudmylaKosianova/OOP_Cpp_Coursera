#pragma once

#include <map>
#include <string>
#include <iostream>
#include <vector>

#include "OrderBookEntry.h"
#include "CSVReader.h"

class Wallet
{
    public:
    Wallet();

    /**puts currency into the wallet */
    void insertCurrency(std::string type, double amount);
    /**removes currency from the wallet */
    bool removeCurrency(std::string type, double amount);
    /**checks if there is the enough amount of currency  */
    bool constainsCurrency(std::string type, double amount);
    /**check if the there is enough currency to fulfil the ask or bid */
    bool canFulfilOrder(OrderBookEntry order);
    /**generates a string representation of a wallet */
    std::string toString();

    private:
    std::map<std::string, double> currencies;
};

#pragma once

#include <map>
#include <string>
#include <iostream>

class Wallet
{
    public:
    Wallet();

    /**puts currency into the wallet */
    void insertCurrency(std::string type, double amount);
    /**checks if there is the enough amount of currency  */
    bool constainsCurrency(std::string type, double amount);
    /**generates a string representation of a wallet */
    std::string toString();

    private:
    std::map<std::string, double> currencies;
};

#include "Wallet.h"

Wallet::Wallet()
{}

void Wallet::insertCurrency(std::string type, double amount)
{
    double balance = 0;
    if(amount < 0) throw std::exception{};
    if(currencies.count(type) != 0) balance = currencies[type];
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    if (amount < 0) return false;
    if (currencies[type]==0) return false;
    if(constainsCurrency(type, amount))
    {
        currencies[type] -= amount;
        return true;
    } 
    else return false;  
}

bool Wallet::constainsCurrency(std::string type, double amount)
{
    if(currencies.count(type) == 0) return false;
    else return currencies[type] >= amount;
}

bool Wallet::canFulfilOrder(OrderBookEntry order)
{
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    if(order.orderType == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currs[0];
    }
    
    return false;
}

std::string Wallet::toString()
{
    std::string s = "";
    for(std::pair<std::string, double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}
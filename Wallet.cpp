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

bool Wallet::constainsCurrency(std::string type, double amount)
{
    if(currencies.count(type) == 0) return false;
    else return currencies[type] >= amount;
}

std::string Wallet::toString()
{
    return "oink";
}
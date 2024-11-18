#pragma once

#include <map>
#include <iostream>

class Wallet
{
    public:
    Wallet();

    private:
    std::map<std::string, double> currency;
};

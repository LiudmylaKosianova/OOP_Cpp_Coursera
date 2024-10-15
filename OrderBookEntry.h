#pragma once

#include <iostream>
#include <string>


enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:

    //constructor
    OrderBookEntry(std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType,
                   double _price,
                   double _amount);

    //data types to represent a the fields in a row in the data file
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
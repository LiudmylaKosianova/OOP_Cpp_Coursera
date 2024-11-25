#pragma once

#include <iostream>
#include <string>


enum class OrderBookType{bid, ask, asksale, bidsale, unknown};

class OrderBookEntry
{
    public:

    //constructor
    OrderBookEntry(std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType,
                   double _price,
                   double _amount,
                   std::string  username = "dataset");

    static OrderBookType stringToOrderBookType(std::string s);

    /**compares OrderBookEntries by timestemp
     * returns true if the first argument is earlier in time than the second
     */
    static bool compareByTimestamp(const OrderBookEntry& a, const OrderBookEntry& b);

    static bool compareByPriceAsc(const OrderBookEntry& a, const OrderBookEntry& b);

    static bool compareByPriceDesc(const OrderBookEntry& a, const OrderBookEntry& b);



    //data types to represent a the fields in a row in the data file
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    std::string username;
};
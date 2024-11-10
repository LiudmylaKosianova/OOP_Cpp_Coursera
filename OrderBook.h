#pragma once

#include <iostream>
#include <OrderBookEntry.h>
#include <CSVReader.h>
#include <string>
#include <vector>


class OrderBook
{
    public:
    /**construct, reading a csv data file */
    OrderBook(std::string filename);
    /**return vector of all known products in the dataset */
    std::vector<std::string> getKnownProduct();
    /**return vector of orders according to the filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                        std::string product,
                                        std::string timestamp); 

    private:
    std::vector<OrderBookEntry> orders;

};
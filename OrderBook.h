#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "CSVReader.h"
#include "OrderBookEntry.h"

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
    /**return the highest price */
    static double getHighPrice(std::vector<OrderBookEntry>& orders);

    static double getLowPrice(std::vector<OrderBookEntry>& orders);
    /**returns the earliest time in the order book */
    std::string getEarliestTime();

    /**return the total amount of a product */
    static double getAmount(std::vector<OrderBookEntry>& orders);

    /**returns the next time after the specified in the argument time,
     * if there is no next time, returns the earliest time
     */
    std::string getNextTime(std::string timestamp);

    private:
    std::vector<OrderBookEntry> orders;

};
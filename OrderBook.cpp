#include "OrderBook.h"

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProduct()
{
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;
    for(OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }

    for(auto const& e : prodMap)
    {
        products.push_back(e.first);
    }
    
    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                        std::string product,
                                        std::string timestamp)
{
    std::vector<OrderBookEntry> ordersV;
    return ordersV;
}
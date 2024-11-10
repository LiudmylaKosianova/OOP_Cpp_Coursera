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
    std::vector<OrderBookEntry> ordersSub;
    for(OrderBookEntry& e : orders)
    {
        if(e.orderType == type && 
           e.product == product &&
           e.timestamp == timestamp)
        {
            ordersSub.push_back(e);
        }
    }

    return ordersSub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double maxPrice = orders[0].price;
    for(const OrderBookEntry& e : orders)
    {
        if(e.price > maxPrice) maxPrice = e.price;
    }

    return maxPrice;

}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double minPrice = orders[0].price;
    for(const OrderBookEntry& e : orders)
    {
        if(e.price < minPrice) minPrice = e.price;
    }

    return minPrice;

}
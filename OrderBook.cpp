#include "OrderBook.h"

OrderBook::OrderBook(std::string filename)
{}
    /**return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProduct()
{}
    /**return vector of orders according to the filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                        std::string product,
                                        std::string timestamp)
{}
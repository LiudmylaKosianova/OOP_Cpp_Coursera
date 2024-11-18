#include "OrderBookEntry.h"



OrderBookEntry::OrderBookEntry(std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType,
                   double _price,
                   double _amount)
    :
     timestamp(_timestamp),
     product(_product),
     orderType(_orderType),
     price(_price),
     amount(_amount)
    {
    
    }

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if(s == "ask")return OrderBookType::ask;
    if(s == "bid")return OrderBookType::bid;
    return OrderBookType::unknown;
}

bool OrderBookEntry::compareByTimestamp(const OrderBookEntry& a, const OrderBookEntry& b)
{
    return a.timestamp < b.timestamp;
}

bool OrderBookEntry::compareByPriceAsc(const OrderBookEntry& a, const OrderBookEntry& b)
{
    return a.price < b.price;
}

bool OrderBookEntry::compareByPriceDesc(const OrderBookEntry& a, const OrderBookEntry& b)
{
    return a.price > b.price;
}
    

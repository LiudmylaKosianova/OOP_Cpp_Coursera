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

double OrderBook::getAmount(std::vector<OrderBookEntry>& orders)
{
    double totalAmount = 0.0;
    for(const OrderBookEntry& e : orders)
    {
        totalAmount += e.amount;
    }

    return totalAmount;

}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string nextTime = "";
    for(OrderBookEntry& e : orders)
    {
        if(e.timestamp > timestamp) 
        {
            nextTime = e.timestamp;
            break;
        }
        if (nextTime == "") nextTime = orders[0].timestamp;
    }
    return nextTime;
}


void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(),OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    // asks = orderbook.asks in this timeframe
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    // bids = orderbook.bids in this timeframe
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    // sales = []
    std::vector<OrderBookEntry> sales;

    // sort asks lowest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    // sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    // for ask in asks:
    for(OrderBookEntry& ask : asks)
    {
        // for bid in bids:
        for(OrderBookEntry& bid : bids)
        {

        // if bid.price >= ask.price # we have a match
        if(bid.price >= ask.price)
        {
            // sale = new orderbookentry()
            // sale.price = ask.price
            OrderBookEntry sale{timestamp,product,OrderBookType::sale,ask.price,0};
        
            // if bid.amount == ask.amount: # bid completely clears ask
            if(bid.amount == ask.amount)
            {
                // sale.amount = ask.amount
                // sales.append(sale)
                // bid.amount = 0 # make sure the bid is not processed again
                // # can do no more with this ask
                // # go onto the next ask
                // break
                sale.amount = sale.amount;
                sales.push_back(sale);
            }

            // if bid.amount > ask.amount: # ask is completely gone slice the bid
            if(bid.amount > ask.amount)
            {
                // sale.amount = ask.amount
                // sales.append(sale)
                // # we adjust the bid in place
                // # so it can be used to process the next ask
                // bid.amount = bid.amount - ask.amount
                // # ask is completely gone, so go to next ask
                // break
            }
            // if bid.amount < ask.amount # bid is completely gone, slice the ask
            if(bid.amount < ask.amount)
            {
                // sale.amount = bid.amount
                // sales.append(sale)
                // # update the ask
                // # and allow further bids to process the remaining amount
                // ask.amount = ask.amount - bid.amount
                // bid.amount = 0 # make sure the bid is not processed again
                // # some ask remains so go to the next bid
                // continue
            }
        }
        }
    }
// return sales
}

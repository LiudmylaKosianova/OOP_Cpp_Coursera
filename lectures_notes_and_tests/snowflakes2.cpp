#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:

    //constructor
    OrderBookEntry(std::string _timestamp,
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
    //data types to represent a the fields in a row in the data file
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
    int ent = 0;
    double PriceSum = 0;
    for(OrderBookEntry& entry : entries)
    {
        PriceSum += entry.price;
        ++ent;        
    } 

    return PriceSum/ent;
}

int main()
{
    
    //a vector of OrderBookEntry objects
    std::vector<OrderBookEntry> orders;

    //adding objects to the vector
    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.02187307,
                                    3.467434});

    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.02187305,
                                    6.85567013});

     orders.push_back(OrderBookEntry{"2020/03/17 17:01:28.884498",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.021873,
                                    1.017});

     orders.push_back(OrderBookEntry{"2020/03/17 17:01:29.880492",
                                    "ETH/BTC",
                                    OrderBookType::bid,
                                    0.0218701,
                                    9.13884513});                                                             

    //iterating (inside the function) over the vector to find the average price
    double EveragePrice = computeAveragePrice(orders);
    std::cout << "Everage price is " << EveragePrice << std::endl;    

    return 0; 
}


 
#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType{bid, offer};

class OrderBookEntry
{
    public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType)
    :price(_price),
     amount(_amount),
     timestamp(_timestamp),
     product(_product),
     orderType(_orderType)
    {
    
    }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};



int main()
{
    OrderBookEntry entry1(1000,
                          0.02,
                          "2020/03/17 17:01:24",
                          "BTC/USDT",
                          OrderBookType::bid);
    std::cout << "The price is " << entry1.price << std::endl;

    std::vector<OrderBookEntry> orders;
    orders.push_back(OrderBookEntry{
                          1000,
                          0.02,
                          "2020/03/17 17:01:24",
                          "BTC/USDT",
                          OrderBookType::bid});

    orders.push_back(OrderBookEntry{
                          3000,
                          0.02,
                          "2020/03/17 17:01:24",
                          "BTC/USDT",
                          OrderBookType::bid});

    //iterator style makes copies 
    for(OrderBookEntry order : orders)
    {
        std::cout << "The price is " << order.price << std::endl;
    }

    //iterator style does not make copies (iterate by reference)
    for(OrderBookEntry& order : orders)
    {
        std::cout << "The price is " << order.price << std::endl;
    }

    //array style
    for(unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders[i].price << std::endl;
    }

    //object style 
    for(unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders.at(i).price << std::endl;
    }

    return 0; 
}

 
#include "CSVReader.h"

CSVReader::CSVReader()
{}
 
vector<OrderBookEntry> CSVReader::readCSV(string CSVFile)
{
    vector<OrderBookEntry> entries;
    return entries;
}

vector<string> CSVReader::tokenise(string csvLine, char separator)
{ 
    vector<string> tokens;
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(vector<string> tokens)
{
    double price, amount;

    if(tokens.size() != 5)
    {
        throw std::exception{};
    }
            
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e)
    {throw;}
    
    OrderBookEntry obe{"","", OrderBookType::bid,1.0,1.0};
    return obe;
}
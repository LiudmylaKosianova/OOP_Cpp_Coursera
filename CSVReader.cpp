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

OrderBookEntry CSVReader::stringsToOBE(vector<string> strings)
{
    OrderBookEntry obe{"","", OrderBookType::bid,1.0,1.0};
    return obe;
}
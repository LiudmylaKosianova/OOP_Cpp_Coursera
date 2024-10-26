#include "CSVReader.h"

CSVReader::CSVReader()
{}
 
vector<OrderBookEntry> CSVReader::readCSV(string CSVFilename)
{
    vector<OrderBookEntry> entries;
    ifstream csvFile{CSVFilename};
    string line;

    if(csvFile.is_open())
    {
        while (getline(csvFile, line))
        {
            OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
            entries.push_back(obe);
        }
        
    }
    return entries;
}

vector<string> CSVReader::tokenise(string csvLine, char separator)
{ 
    vector<string> tokens;
    int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    string token;

    do
    {
        end = csvLine.find_first_of(separator, start);
        if(start == csvLine.length()||start == end) break;

        if(end >= 0)token = csvLine.substr(start, end-start);
        else token = csvLine.substr(start, csvLine.length()-start);

        tokens.push_back(token);
        start = end + 1;

    }while(end > 0);

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

    OrderBookEntry obe{tokens[0],
                       tokens[1],
                       OrderBookEntry::stringToOrderBookType(tokens[2]),
                       price,
                       amount};
    return obe;
}
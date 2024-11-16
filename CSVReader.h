#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "OrderBookEntry.h"

using std::string;
using std::vector;
using std::ifstream;
using std::getline;

class CSVReader
{
    public:
    CSVReader();
    static vector<OrderBookEntry> readCSV(string CSVFile);
    static vector<string> tokenise(string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::string timestamp,
                                       std::string product,
                                       OrderBookType orderBookType,
                                       std::string price,
                                       std::string amount);

    private:
    static OrderBookEntry stringsToOBE(vector<string> strings);
};

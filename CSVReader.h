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

    private:
    static vector<string> tokenise(string csvLine, char separator);
    static OrderBookEntry stringsToOBE(vector<string> strings);
};

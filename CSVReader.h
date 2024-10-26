#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "OrderBookEntry.h"

using std::string;
using std::vector;

class CSVReader
{
    public:
    CSVReader();
    static vector<OrderBookEntry> readCSV(string CSVFile);

    private:
    static vector<string> tokenise(string csvLine, char separator);
    static OrderBookEntry stringsToOBE(vector<string> strings);
};

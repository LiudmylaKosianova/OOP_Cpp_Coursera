#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    std::string token;

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

int main()
{
    // std::string s = "one,two,three";
    // std::string s1 = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    // tokens = tokenise(s1, ',');
    // for(const std::string& t : tokens)
    // {
    //     std::cout << t << std::endl;
    // }

    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if(csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            tokens = tokenise(line, ',');
            if(tokens.size() != 5)
            {
                continue;
            }
            double price = std::stod(tokens[3]);
            double amount = std::stod(tokens[4]);
        }
        csvFile.close();
    }
    else
    {
        std::cout << "File is not open" << std::endl;
    }

    return 0;
}
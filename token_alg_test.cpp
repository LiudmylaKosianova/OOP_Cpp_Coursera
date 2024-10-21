#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;

    int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    do
    {
        end = csvLine.find_first_of(separator, start);
        if(start == csvLine.length()||start == end) break;

    }while();
    return tokens;
}

int main()
{


    return 0;
}
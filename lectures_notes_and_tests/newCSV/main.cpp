#include "Student.h"
#include <fstream>
using std::ifstream;
using std::stoi;

vector<string> tokenise(string csvLine, char separator)
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

int main()
{
    
    ifstream csvFile{"StudentPerformanceFactors.csv"};
    string line;
    vector<string> tokens;
    vector<Student> students;

    int linesN = 0;
    int maleS = 0;
    int femaleS = 0;

    if(csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            tokens = tokenise(line, ',');
            if(tokens.size() != 20){continue;} 
        
            try
            {
                int hoursStudy = stoi(tokens[0]);
                int sleepHours = stoi(tokens[5]);
                int examScore = stoi(tokens[19]);

                students.push_back(Student{hoursStudy,
                                            sleepHours,
                                            tokens[12],
                                            tokens[18],
                                            examScore});

            }catch(std::exception& e){continue;}

            ++linesN;
            if(tokens[18] == "Male") ++maleS;
            else ++femaleS;
            
        }
        csvFile.close();
    }
    else
    {
        std::cout << "Could not open the file" << std::endl;
    }
    std::cout << "Number of lines parced: " << linesN << std::endl;
    std::cout << "Number of male students: " << maleS << std::endl;
    std::cout << "Number of female students: "<< femaleS << std::endl;

    return 0;
}
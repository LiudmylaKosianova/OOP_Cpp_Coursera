#include <iostream>
using namespace std;


int main()
{
    //menu options
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Place an offer" << endl;
    cout << "4: Place a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    
    //read user input
    int userOption;
    cout << "Type in 1-6" << endl;
    cin >> userOption;

    return 0;
}
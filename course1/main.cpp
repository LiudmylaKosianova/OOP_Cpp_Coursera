#include <iostream>
using namespace std;


int main()
{
    while(true)
    {
    //menu options
    cout << "=======MENU=======" << endl;
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

    //check user input and take actions
    switch(userOption)
    {
        case 1:
        cout << "Follow the instructions. Your goal is to make money." << endl;
        break;
        case 2:
        cout << "Your stats are empty." << endl;
        break;
        case 3:
        cout << "Specify what you want to sell." << endl;
        break;
        case 4:
        cout << "Specify what you want to buy." << endl;
        break;
        case 5:
        cout << "Your wallet is empty." << endl;
        break;
        case 6:
        cout << "Moving on." << endl;
        break;
        default:
        cout << "Bad input. Please, choose the number 1-6." << endl;
        break;
    }
    }
    

    return 0;
}
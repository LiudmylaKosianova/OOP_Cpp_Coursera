#include <iostream>
using namespace std;

void printMenu()
{ 
    cout << " " << endl;
    cout << "=======MENU=======" << endl;
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Place an offer" << endl;
    cout << "4: Place a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "==================" << endl;
}

int getUserOption()
{
    //get user option
    cout << "" << endl;
    cout << "Type in 1-6: ";
    int userOption;
    cin >> userOption;
    return userOption;
}

void printHelp()
{
    cout << "Follow the instructions. Your goal is to make money." << endl;
}

void printStats()
{
    cout << "Your stats are empty." << endl;
}

void printOffer()
{
    cout << "Specify what you want to sell." << endl;
}

void printBid()
{
    cout << "Specify what you want to buy." << endl;
}

void printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void goNext()
{
    cout << "Moving on." << endl;
}

void processUserOption(int userOption)
{
    //check user input and take actions
    switch(userOption)
    {
        case 1:
        printHelp();
        break;
        case 2:
        printStats();
        break;
        case 3:
        printOffer();
        break;
        case 4:
        printBid();
        break;
        case 5:
        printWallet();
        break;
        case 6:
        goNext();
        break;
        default:
        cout << "Bad input. Please, choose the number 1-6." << endl;
        break;
    }
}

int main()
{
    while(true)
    {
        printMenu();  
        int userOption = getUserOption(); 
        processUserOption(userOption);    
    }    

    return 0;
}
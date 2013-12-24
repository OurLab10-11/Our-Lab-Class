#include <iostream>
#include <string>
#include <vector>
#include "IOHandler.h"
#include "Complex.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::getline;
using std::endl;

int currentStep;


int main()
{
    IOHandler handler;

    string currentCommand;
    
    while (true)
    {
        cout << "In" << "[" << currentStep << "] > ";

        getline(cin, currentCommand);

        if (!currentCommand.compare("exit"))
            break;
        else
        {
            string response = handler.executeCommand(currentCommand);

            cout << "Out" << "[" << currentStep++ << "] > ";
            cout << response << endl;
        }
    }

    return 0;
}
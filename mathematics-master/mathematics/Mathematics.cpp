#pragma warning (disable: 4018)
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
    handler.counter = currentStep;
    string currentCommand;
    
    while (true)
    {
        cout << "In" << "[" << handler.counter << "] > ";
    
        getline(cin, currentCommand);

        if (!currentCommand.compare("exit"))
            break;
        else
        {
            Polynom<int> response = handler.executeCommand(currentCommand);

            cout << "Out" << "[" << handler.counter << "] > ";
            cout << response << endl;
        }
    }

    return 0;
}
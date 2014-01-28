#include <iostream>
#include <string>
#include <vector>
#include "IOHandler.h"
#include "Complex.h"
#include "Polynom.h"

using namespace std;

int main()
{
    IOHandler handler;
    string currentCommand;
    while (true)
    {
        cout << "In" << "[" << handler.counter << "] > ";
        getline(cin, currentCommand);
        if (!currentCommand.compare("exit"))
            break;
        else
        {
            vector<Polynom<Complex<Rational>>> response = handler.executeCommand(currentCommand);
            for (unsigned int i = 0; i < response.size(); ++i)
            {
                cout << "Out" << "[" << handler.counter + i << "] > ";
                cout << response[i] << endl;
            }
            handler.counter +=response.size();
        }
    }
    return 0;
}
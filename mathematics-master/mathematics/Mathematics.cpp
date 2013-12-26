#include <iostream>
#include <string>
#include <vector>
#include "IOHandler.h"
#include "Complex.h"
#include "Polynom.h"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::getline;
using std::endl;

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
            vector<Polynom<int>> response = handler.executeCommand(currentCommand);
            for (int i = 0; i < response.size(); ++i)
            {
                cout << "Out" << "[" << handler.counter + i << "] > ";
                cout << response[i] << endl;
            }
            handler.counter +=response.size();
        }
    }
    return 0;
}
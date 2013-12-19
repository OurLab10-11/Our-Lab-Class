#include "IOHandler.h"
#include "Number.h"

using std::string;

int IOHandler::getCurrentStep()
{
    return counter;
}

Polynom<Number> IOHandler::executeCommand(string command)
{
    ++counter;
    Result response = parser.command(command);
    Polynom<Number> result = solver.execute(response);
    //to do
    //adding newNames if non-empty.
    //
    return result;
}

IOHandler::IOHandler()
{
    parser = Parser(*this);
    counter = 0;
}

Polynom<Number> IOHandler::getPreviousResult(int number)
{
    //to do
    //must throws exception if number out of bounds
    return previousResults[number];
}

Polynom<Number> IOHandler::getVariable(string variableName)
{
    //extracting from the map value of variableName
    //must throws exception if variable with this name does not exist.

    //return map.get(variableName);
}


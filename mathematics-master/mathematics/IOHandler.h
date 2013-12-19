#pragma once;
#include <string>
#include "Polynom.h"
#include "Parser.h"
#include "Result.h"
#include "Solver.h"

using std::string;

class IOHandler
{
private:
    int counter;
    Parser parser;
    Solver solver;
    map<string, Polynom<Number>> polynoms; //  variables
    vector<Polynom<Number>> previousResults; // to support previous polynoms calls.
public:
    IOHandler();

    int getCurrentStep();
    Polynom<Number> executeCommand(string command);

    //2 methods for solver.
    Polynom<Number> getVariable(string variableName);
    Polynom<Number> getPreviousResult(int number);

};

#pragma once;
#include "Result.h"
#include "Polynom.h"
#include <string>
#include <map>
using std::string;

class Solver
{
private:
    map<string, Polynom<Number>> newNames;
    Result opz;
    Result initial;

    void makeOPZ();
    void makeEquals();
    void init(const Result& r);
public:
    map<string, Polynom<Number>> getEquals();
    Polynom<Number> execute(const Result& r);
};
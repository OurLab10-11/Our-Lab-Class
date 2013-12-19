#include "Solver.h"
#include "Map.h"
void Solver::makeOPZ()
{
    //to do OPZ from tokens.
    //initial is the field already partitioned.
    //just make opz from it and write to opz field.
}

void Solver::makeEquals()
{
    //to do
    //add to newNames all equals
    //received from current command
}

void Solver::init(const Result& r)
{
    initial = r;
    makeOPZ();
    makeEquals();
}

Polynom<Number> Solver::execute(const Result& r)
{
    init(r);
    //executing opz
    //must return polynom
}

map<string, Polynom<Number>> Solver::getEquals()
{
    return newNames;
}


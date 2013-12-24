#pragma once
#include <string>
#include "Map.h"
#include "Number.h"
#include "Result.h"

using std::string;

class Solver
{
private:
    //Map<string, Polynom<int>> newNames;
    Result opz;
    Result initial;
    void makeOPZ()
    {
        return;
        //to do OPZ from tokens.
        //initial is the field already partitioned.
        //just make opz from it and write to opz field.
    }
    void makeEquals()
    {
        return;
        //to do
        //add to newNames all equals
        //received from current command    
    };
    void Solver::init(const Result& r)
    {
        initial = r;
        makeOPZ();
        makeEquals();
    };
public:
    //Map<string, Polynom<int>> getEquals();
    string execute(const Result& r)
    {
        init(r);
        //executing opz
        //must return polynom
        return "";
    }
};
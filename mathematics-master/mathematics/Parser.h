#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "Result.h"

using std::string;
using std::stack;

bool isOperation(char a);
bool isValue(char a);
bool isVariable(char a);
bool isSeparator(char a);
bool isBraket(char a);
bool checkUp(string temp);

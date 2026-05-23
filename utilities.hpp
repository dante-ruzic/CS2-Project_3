#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include "stack.hpp"
#include "string.hpp"

String convertInfixToPostfix(const String& expr);
String evaluate(String, String, String, int&, std::ostream&);
void generateAssembly(const String&, std::ostream&);
#endif
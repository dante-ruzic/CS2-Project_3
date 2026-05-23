#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {
 
    Stack<int> x;
    assert(x.empty() == true);


    Stack<String> y;
    assert(y.empty() == true);

    std::cout << "Done testing default constructor.\n";
    return 0;
}
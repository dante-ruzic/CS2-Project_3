#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {
    Stack<String> x;
    x.push(String("One"));
    x.push(String("Two"));
    x.push(String("Three"));

    Stack<String> y(x); 

    assert(x == y);
    

    x.pop();
    assert(!(x == y));
    assert(y.top() == String("Three"));

    std::cout << "Done testing copy constructor.\n";
    return 0;
}
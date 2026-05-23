#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {
    Stack<int> x;
    x.push(10);
    x.push(20);

    Stack<int> y;
    y.push(99); 

    y = x;

    assert(x == y);
    assert(y.top() == 20);
    

    x.pop();
    assert(!(x == y));
    assert(y.top() == 20); 

    std::cout << "Done testing assignment operator.\n";
    return 0;
}
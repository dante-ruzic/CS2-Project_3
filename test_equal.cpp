#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {
    Stack<int> x;
    Stack<int> y;
    
    assert(x == y);

    x.push(1);
    x.push(2);
    x.push(3);

    y.push(1);
    y.push(2);
    y.push(3);
    
    assert(x == y);

    y.pop();
    assert(!(x == y)); 

    y.push(99);
    assert(!(x == y)); 

    std::cout << "Done testing operator==.\n";
    return 0;
}
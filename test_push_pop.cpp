#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {

    Stack<int> x;
    x.push(10);
    assert(!x.empty());
    assert(x.top() == 10);
    
    x.push(20);
    assert(x.top() == 20);
    
    int val = x.pop();
    assert(val == 20);
    assert(x.top() == 10);
    
    x.pop();
    assert(x.empty());


    Stack<String> y;
    y.push(String("Hello"));
    assert(y.top() == String("Hello"));
    
    y.push(String("World"));
    assert(y.top() == String("World"));
    
    String strVal = y.pop();
    assert(strVal == String("World"));
    assert(y.top() == String("Hello"));

    std::cout << "Done testing push and pop.\n";
    return 0;
}
#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"

int main() {
    Stack<String> x;
    x.push(String("A"));
    x.push(String("B"));

    Stack<String> y;
    y.push(String("X"));
    y.push(String("Y"));
    y.push(String("Z"));

    x.swap(y);

    assert(x.pop() == String("Z"));
    assert(x.pop() == String("Y"));
    assert(x.pop() == String("X"));
    assert(x.empty());

    assert(y.pop() == String("B"));
    assert(y.pop() == String("A"));
    assert(y.empty());

    std::cout << "Done testing swap.\n";
    return 0;
}
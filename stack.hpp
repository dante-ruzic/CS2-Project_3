//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2025
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>

template<typename T> 
class Node {
public:
    T data;
    Node<T>* next;
    
private:
    
};

// CLASS INV:
//
template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();
    void swap(Stack<T>&);
    Stack<T>& operator=(const Stack<T>&);
    bool operator==(const Stack<T>&) const;

    bool empty() const;
    bool full() const;
    T top() const;
    T pop();
    void push(const T&);

private:
	Node<T> *tos;
};
#include "stack.cpp"
#endif
#include <iostream>
#include "stack.hpp"
#include <cassert>



template <typename T>
Stack<T>::Stack()
{
    tos = nullptr;
}
template <typename T>
Stack<T>::Stack(const Stack<T>& x)
{
    Node<T>* temp = x.tos;
    Node<T>* prev = nullptr;
    while (temp != nullptr)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = temp->data;
        newNode->next = nullptr;
        if (prev == nullptr)
            tos = newNode;
        else
            prev->next = newNode;
        prev = newNode;
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::~Stack()
{
    while(tos != nullptr)
    {
        Node<T>* temp = tos;
        tos = tos->next;
        delete temp;
    }
}
template <typename T>
void Stack<T>::swap(Stack<T>& x)
{
    Node<T>* temp = tos;
    tos = x.tos;
    x.tos = temp;
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& x)
{
    Stack<T> temp(x);
    swap(temp);
    return *this;
}
template <typename T>
bool Stack<T>::operator==(const Stack<T>& x) const
{
    Node<T>* temp1 = tos;
    Node<T>* temp2 = x.tos;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1 == nullptr && temp2 == nullptr;
}
template <typename T>
bool Stack<T>::empty() const
{
    return tos == nullptr;
}
template <typename T>
bool Stack<T>::full() const
{
    return false;
}
template <typename T>
T Stack<T>::top() const
{
    assert(tos != nullptr);
    return tos->data;
}
template <typename T>
T Stack<T>::pop()
{
    assert(tos != nullptr);
    Node<T>* temp = tos;
    T data = temp->data;
    tos = tos->next;
    delete temp;
    return data;
}
template <typename T>
void Stack<T>::push(const T& x)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->next = tos;
    tos = newNode;
}
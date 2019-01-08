/**************************
*   Node header file
*   Last Modified: 1/7/18
*   Author: Lucas Mason
**************************/

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::ostream;

template <class T>
class Node 
{
public:
    Node();
    Node(T &data, Node<T> *pNode = nullptr);
    Node(Node<T> *pCopy);

    Node<T> *getNextPtr();
    void setNextPtr(Node<T> *pNext);

    T &getData();
    void setData(T &data);

    void print();
private:
    Node<T> *pNext;
    T data;
};
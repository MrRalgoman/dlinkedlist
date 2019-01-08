/**************************
*   Node header file
*   Last Modified: 1/7/18
*   Author: Lucas Mason
**************************/
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
    Node(T &data, Node<T> *node = nullptr);
    Node(Node<T> *copy);
    ~Node();

    Node<T> *getNextPtr();
    Node<T> *getLastPtr();
    void setNextPtr(Node<T> *node);
    void setLastPtr(Node<T> *node);

    T &getData();
    void setData(T &data);

    void print();
private:
    Node<T> *next;
    Node<T> *last;
    T data;
};

// Node constructor
template <class T>
Node<T>::Node()
{
    this->pNext = nullptr;
}

// Overloaded Node constructor
template <class T>
Node<T>::Node(T &data, Node<T> *node)
{
    this->data = data;
    this->next = node;
}

// Node copy constructor
template <class T>
Node<T>::Node(Node<T> *copy)
{
    this->data = copy->getData();
    this->next = copy->getNextPtr(); 
}

// Node destructor
template <class T>
Node<T>::~Node()
{
    cout << "Inside node destructor.\n";
}

// Gets Node next ptr
template <class T>
Node<T> *Node<T>::getNextPtr()
{
    return this->next;
}

// Gets Node last ptr
template <class T>
Node<T> *Node<T>::getLastPtr()
{
    return this->last;
}

// Sets Node next ptr
template <class T>
void Node<T>::setNextPtr(Node<T> *node)
{
    this->next = node;
}

// Sets Node last ptr
template <class T>
void Node<T>::setLastPtr(Node<T> *node)
{
    this->last = node;
}

// Gets Node data
template <class T>
T &Node<T>::getData()
{
    return this->data;
}

// Sets Node data
template <class T>
void Node<T>::setData(T &data)
{
    this->data = data;
}

// Prints Node
template <class T>
void Node<T>::print()
{
    cout << this->data << '\n';
}

// Overloads << operator to print Node
template <class T>
ostream & operator <<(ostream &lhs, Node<T> *rhs)
{
    lhs << rhs->getData();

    return lhs;
}
/**************************
*   DLinkedList header file
*   Last Modified: 1/9/18
*   Author: Lucas Mason
**************************/
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "node.hpp"

template <class T>
class DLinkedList
{
public:
    DLinkedList();
    DLinkedList(DLinkedList<T> &copyList);
    ~DLinkedList();

    void setHeadPtr(Node<T> *node);
    void setTailPtr(Node<T> *node);
    Node<T> *getHeadPtr();
    Node<T> *getTailPtr();
    unsigned int &len();

    void insertFront(T &data);
    void insertInOrder(T &data);
    void insertBack(T &data);
    T &popFront();
    T &popBack();
    bool isEmpty();
    void print();

private:
    Node<T> *head;
    Node<T> *tail;
    unsigned int size;
};

// DLinkedList constructor
template <class T>
DLinkedList<T>::DLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// DLinkedList copy constructor
template <class T>
DLinkedList<T>::DLinkedList(DLinkedList<T> &copyList)
{
    if (!copyList.isEmpty()) {
        Node<T> *cpyItr = copyList.getHeadPtr();
        this->head = new Node<T>(cpyItr);
        Node<T> *itr = this->head;

        while (cpyItr->getNextPtr()) {
            itr->setNextPtr(new Node<T>(cpyItr->getNextPtr()));

            itr = itr->getNextPtr();
            cpyItr = cpyItr->getNextPtr();

            this->tail = itr;
        }
    }
}

// DLinkedList destructor
template <class T>
DLinkedList<T>::~DLinkedList()
{
    if (!this->isEmpty()) {
        Node<T> *itr = this->head;

        while(itr) {
            Node<T> *temp = itr;

            itr = itr->getNextPtr();

            delete temp;
        }
    }
}

// Sets DLinkedList head ptr
template <class T>
void DLinkedList<T>::setHeadPtr(Node<T> *node)
{
    this->head = node;
}

// Sets DLinkedList tail ptr
template <class T>
void DLinkedList<T>::setTailPtr(Node<T> *node)
{
    this->tail = node;
}

// Gets DLinkedList head ptr
template <class T>
Node<T> *DLinkedList<T>::getHeadPtr()
{
    return this->head;
}

// Gets DLinkedList tail ptr
template <class T>
Node<T> *DLinkedList<T>::getTailPtr()
{
    return this->tail;
}

// Gets length of the DLinkedList
template <class T>
unsigned int &DLinkedList<T>::len()
{
    return this->size;
}

// Inserts into front of the DLinkedList
template <class T>
void DLinkedList<T>::insertFront(T &data)
{
    if (this->isEmpty()) {
        this->head = new Node<T>(data);
        this->tail = this->head;
        this->size = 1;
    } else {
        Node<T> *temp = new Node<T>(data);
        temp->setNextPtr(this->head);
        this->head->setLastPtr(temp);

        this->head = temp;
        this->size++;
    }
}

// Inserts in order into the DLinkedList
template <class T>
void DLinkedList<T>::insertInOrder(T &data)
{
    
}

// Inserts into back of the DLinkedList
template <class T>
void DLinkedList<T>::insertBack(T &data)
{
    if (this->isEmpty()) {
        this->tail = new Node<T>(data);
        this->head = this->tail;
        this->size = 1;
    } else {
        Node<T> *temp = new Node<T>(data);
        temp->setLastPtr(this->tail);
        this->tail->setNextPtr(temp);

        this->tail = temp;
        this->size++;
    }
}

// Pops off the first item from the DLinkedList
template <class T>
T &DLinkedList<T>::popFront()
{

}

// Pops off the last item from the DLinkedList
template <class T>
T &DLinkedList<T>::popBack()
{

}

// Return true if DLinkedList is empty false otherwise
template <class T>
bool DLinkedList<T>::isEmpty()
{
    return (this->size == 0);
}

// Prints DLinkedList Nodes
template <class T>
void DLinkedList<T>::print()
{
    if (!this->isEmpty()) {
        Node<T> *itr = this->head;

        while (itr) {
            cout << itr << '\n';

            itr = itr->getNextPtr();
        }
    }
}

#endif
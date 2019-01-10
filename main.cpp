#include "dlinkedlist.hpp"

int main(void)
{
    int vals[5] = { 1, 2, 3, 4, 5 };

    DLinkedList<int> list;

    for (int i = 0; i < 5; i++) {
        list.insertBack(vals[i]);
    }

    cout << "List len: " << list.len() << '\n';

    //DLinkedList<int> list2(list);

    list.print();
    //list2.print();
}
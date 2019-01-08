#include "node.hpp"

int main(void)
{
    int val = 5;

    Node<int> *node = new Node<int>(val);

    cout << node << '\n';
}
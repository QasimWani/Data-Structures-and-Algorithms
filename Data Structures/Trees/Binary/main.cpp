#include <cstdlib>
#include <iostream>
#include "Tree.cpp"
using namespace std;

int main()
{
    Tree* tree = new Tree();
    tree->newNode(1);
    tree->newNode(2);
    tree->newNode(7);
    tree->newNode(19);
    tree->newNode(3);
    tree->newNode(12);
    tree->printTree();
    return 0;
}

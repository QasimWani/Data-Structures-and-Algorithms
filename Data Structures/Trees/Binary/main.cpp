#include <cstdlib>
#include <iostream>
#include "Tree.cpp"
using namespace std;

int main()
{
    Tree* tree = new Tree();
    int data = 0, isContinue = 0;
    if(tree->isEmpty())
    {
        cout << "Tree is Empty.";
    }
    while (isContinue != -1)
    {
        cout << "\nAdd Node to Binary Tree (or -1 to Quit): ";
        cin >> isContinue;
        tree->root = tree->newNode(tree->root, isContinue);
    }
    cout << "Tree Structure Completed..." << endl;
    while (data != -1)
    {
        cout << "\nWhat value would you like to search in the binary tree? (-1 to Quit): ";
        cin >> data;
        bool isPresent = tree->printTree(tree->root, data);
        if(isPresent)
        {
            cout << "Value found."<<endl;
        }
        else
        {
            cout << "Value : " << data << " not found";
        }
        
    }
    cout << "Exiting Binary Depth Traversal Search." << endl;
    if(!tree->isEmpty())
    {
        cout << "Tree is NOT Empty.";
    }
    return 0;
}

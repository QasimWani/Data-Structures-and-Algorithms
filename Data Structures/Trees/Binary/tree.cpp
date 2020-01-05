#include <iostream>
#include <cstdlib>
#include "Tree.h"
using namespace std;

Tree::Tree()
{
    root = NULL;
    temp = NULL;
    current = NULL;
}

void Tree::newNode(int data)
{
    
    // nodePtr n = new node;
    // n->data = data;
    // n->left = n->right = NULL;

    // if(isEmpty())
    // {
    //     root = n;
    // }
    // else
    // {
    //     current = root;
    //     while(current == NULL)
    //     {
    //         if(n->data <= current->data)
    //         {
    //             current->left = n;
    //             current = n;
    //         }
    //         else
    //         {
    //             current->right = n;
    //             current = n;
    //         }
    //     }
    // }
    
}

bool Tree::isEmpty()
{
    if(root == NULL)
    {
        return true;
    }
    return false;
}

int Tree::getNode(nodePtr element)
{
    if(!isEmpty())
    {
        //Traversal Methods.
    }
    return -1;
}

void Tree::printTree()
{
    // current = temp;
    // if(isEmpty())
    // {
    //     cout << "Tree Empty." << endl;
    // }
    // else
    // {
    //     cout << current->data << endl;
    //     current = current->left;
    //     cout << current->data << endl;
    // }
}
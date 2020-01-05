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
Tree::nodePtr Tree::insertOne(nodePtr rootN, int data)
{
    nodePtr n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
void Tree::newNode(nodePtr rootPtr, int data)
{
    
    nodePtr n = new node;
    if(isEmpty())
    {
        root = n;
    }
    else
    {
        if(n->data <= root->data)
        {
            n->left = insertOne(root, data);
        }
        else
        {
            n->right = insertOne(root, data);
        }
        
    }
    
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

void Tree::printTree(nodePtr rootPtr)
{
    current = rootPtr;
    if(isEmpty())
    {
        cout << "Tree Empty." << endl;
    }
    else
    {
        cout << current->data << endl;
        if(current->left != NULL)
        {
            current = current->left;
            printTree(current);
        }
        else
        {
            current = current->right;
            printTree(current);
        }
        
    }
    
}
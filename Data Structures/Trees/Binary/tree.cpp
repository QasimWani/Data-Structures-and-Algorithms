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

Tree::nodePtr Tree::newNode(nodePtr root, int data)
{
    if(root == NULL)
    {
        root = getNode(data);
        return root;
    }
    if(data <= root->data)
    {
        root->left = newNode(root->left, data);
    }
    else
    {
        root->right = newNode(root->right, data);
    }
    return root;
    
}

Tree::nodePtr Tree::getNode(int data)
{
   nodePtr newNode = new node();
   newNode->data = data;
   newNode->left = newNode->right = NULL;
   return newNode;
}

bool Tree::isEmpty()
{
    if(root == NULL)
    {
        return true;
    }
    return false;
}



bool Tree::printTree(nodePtr rootPtr, int data)
{
    if(rootPtr == NULL)
    {
        return false;
    }
    else if(data == rootPtr->data)
    {
        return true;
    }
    else if(data <= rootPtr->data)
    {
        return printTree(rootPtr->left, data);
    } 
    else
    {
        return printTree(rootPtr->right, data);
    }
}


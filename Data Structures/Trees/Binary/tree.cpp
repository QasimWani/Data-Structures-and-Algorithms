#include <iostream>
#include <cstdlib>

#include "Tree.h"
using namespace std;

template<class T>
Tree<T>::Tree()
{
    root = NULL;
    temp = NULL;
    current = NULL;
}

template<class T>
void Tree<T>::addChild(T data, node position)
{
    
}

template<class T>
bool Tree<T>::isEmpty()
{
    if(root == NULL)
    {
        return true;
    }
    return false;
}

template<class T>
T Tree<T>::getNode(node element)
{
    if(!isEmpty())
    {
        
    }
    return -1;
}

#include <cstdlib>
#include "Heap.h"
#include <iostream>
#include <vector>

Heap::Heap()
{
   * H = NULL; // array
    max_size = 1; //maximum possible size of *H.
    current_size = 0; //latest accessible element of heap array H. 
}

Heap::~Heap()
{
    delete &Heap();
}

bool Heap::isEmpty()
{
    if(current_size > 0)
    {
        return true;
    }
    return false;
}

int Heap::extractMax()
{
    if(!isEmpty())
    {
        return H[0];
    }
    return -1;
}

int Heap::getParent(int index)
{
    if(isEmpty())
    {
        return -1;
    }
    return floor(H[index]/2);
}

int * Heap::getSiblings(int index)
{
    if(isEmpty())
    {
        return nullptr;
    }
    int siblings[2] = {H[2*index], H[(2*index) + 1]};
    return siblings;
}

int * Heap::getNodeInformation(int index)
{
    int parent = getParent(index);
    int * siblings = getSiblings(index);
    int information[3] = {parent, siblings[0], siblings[1]};
    return information;
}

void Heap::insert(int data)
{
    
}
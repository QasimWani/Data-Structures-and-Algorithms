#include <cstdlib>
#include <iostream>
#include "Heap.h"
#include <vector>
#include <cmath>
using namespace std;


Heap::Heap()
{
    H = NULL; // array
    temp = NULL;
    siblings [2] = {};
    current_size = 1; //latest accessible element of heap array H. 
    flag = 0; //used in iterations for private sort();
    arr = new vector<int>;
    arr->push_back(0);
}

bool Heap::isEmpty()
{
    if(H == NULL)
    {
        return false;
    }
    return true;
}


int Heap::getParent(int index)
{
    if(isEmpty())
    {
        return -1;
    }
    return (H[index]/2);
}

int * Heap::getSiblings(int index)
{
    if(current_size == 1 || current_size < (2*index))
    {
        return nullptr;
    }

    siblings[0] = H[2*index];
    siblings[1] = -1;
    if(current_size >= 2*index + 1)
    {
        siblings[1] = H[2*index + 1];
    }
    return siblings;
}

int * Heap::getNodeInformation(int index)
{
    int parent = getParent(index);
    int * siblings = getSiblings(index);
    int * information;
    information[0] = parent;
    if(siblings != nullptr)
    {
        information[1] = siblings[0];
        information[2] = siblings[1];
    }
    return information;
}

void Heap::insert(int data)
{
    arr->push_back(data);
    H = &*arr->begin();
    current_size++;
    // H = sort(H, current_size);
}

void Heap::printHeap()
{
    current_size--;
    H = sort(current_size);
    for (int i = 1; i <= current_size; i++)
    {
        cout << H[i] << endl;
    }
    current_size++;
}

int Heap::extractMax()
{
    int front = arr->front();
    arr->erase(arr->begin());
    H = &*arr->begin();
    H = sort(current_size);
    return front;
}

int * Heap::sort(int curr_size)
{
    if(curr_size < 1)
    {
        return H;
    }
    int size_temp = curr_size;
    int * siblings = getSiblings(size_temp);
    int num_parent = H[size_temp];
    if(siblings != nullptr)
    {
        int max_num = siblings[1];
        int index_max_sibling = 2*size_temp + 1;
        if(siblings[0] > siblings[1])
        {
            max_num = siblings[0];
            index_max_sibling-=1;
        }
        if (num_parent < max_num)
        {
            H[size_temp] = max_num;
            H[index_max_sibling] = num_parent;
            flag++;
            size_temp *= 2;
        }
        else
        {
            size_temp--;
        }
        return sort(size_temp);
    }
    else
    {
        if(flag == 0)
        {
            size_temp-=1;
        }
        else
        {
            if (flag > 0)
            {
                size_temp /= 2;
                flag-=1;
                sort(size_temp);
            }
        }
        return sort(size_temp);
    }
    return H;
}

void Heap::remove(int index)
{
    int front = arr->front();
    if (index < current_size)
    {
        arr->erase(arr->begin()+index);
        H = &*arr->begin();
        H = sort(current_size);
        current_size--;
    }
    else
    {
        cout << "Index out of bounds." << endl;
    }
    
}
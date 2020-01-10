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
    current_size = 0; //latest accessible element of heap array H. 
    flag = 0; //used in iterations for private sort();
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
    return (H[index]/2);
}

int * Heap::getSiblings(int index)
{
    if(isEmpty() || current_size <= (2*index) + 1)
    {
        return nullptr;
    }
    vector<int>vec;
    vec.push_back(H[(2*index) + 1]);
    if(((2*index)+2) >= current_size)
    {
        vec.push_back(H[(2*index) + 2]);
    }
    else
    {
        vec.push_back(-1);
    }
    
    vec.clear();
    int * siblings = &*vec.begin();
    return siblings;
}

int * Heap::getNodeInformation(int index)
{
    int parent = getParent(index);
    int * siblings = getSiblings(index);
    int information[3] = {parent, -1, -1};
    if(siblings != nullptr)
    {
        information[1] = siblings[0];
        information[2] = siblings[1];
    }
    return information;
}

void Heap::insert(int data)
{
    arr.push_back(data);
    H = &*arr.begin();
    H = sort(H, current_size, false);
    current_size++;
}

void Heap::printHeap()
{
    for (int i = 0; i < current_size; i++)
    {
        cout << H[i] << endl;
    }
}

int Heap::extractMax()
{
    int front = arr.front();
    arr.erase(arr.begin());
    H = &*arr.begin();
    H = sort(H, current_size, false);
    return front;
}

int * Heap::sort(int * arr, int curr_size, bool type_order)
{
    if(curr_size < 0)
    {
        return nullptr;
    }
    int size_temp = curr_size;
    int * siblings = getSiblings(size_temp);
    int num_parent = arr[size_temp];
    
    if(siblings != nullptr)
    {
        int max_num = siblings[1];
        int index_max_sibling = 2*size_temp + 2;
        if(siblings[0] > siblings[1])
        {
            max_num = siblings[0];
            index_max_sibling--;
        }
        if (num_parent < max_num)
        {
            arr[size_temp] = max_num;
            arr[index_max_sibling] = num_parent;
            type_order = true;
            flag++;
        }
    }
    else
    {
        /*
         * 2x1 Multiplexer.
         */
        if(type_order)
        {
            size_temp *= 2;
        }
        else
        {
            if(flag == 0)
            {
                size_temp--;
            }
            else
            {
                while (flag != 0)
                {
                    size_temp /= 2;
                    flag--;
                }
            }
            
        }
        sort(arr, size_temp, type_order);
    }
    return arr;
}

void Heap::remove(int index)
{
    int front = arr.front();
    if (index < current_size)
    {
        arr.erase(arr.begin()+index);
        H = &*arr.begin();
        H = sort(H, current_size, false);
    }
    else
    {
        cout << "Index out of bounds." << endl;
    }
}
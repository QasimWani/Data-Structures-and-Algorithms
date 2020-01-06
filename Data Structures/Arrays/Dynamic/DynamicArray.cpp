#include <cstdlib>
#include <iostream>
#include "DynamicArray.h"

using namespace std;



DynamicArray::DynamicArray(int initial_size)
{
    arr_size = 0;
    arr = new int[initial_size];
    length = initial_size;

}

bool DynamicArray::isRetrievable(int index)
{
    if(index < 0 || index > length)
    {
        return false;
    }
    return true;
}

int DynamicArray::get(int index)
{
    int number = -1;
    if(isRetrievable(index))
    {
        number = arr[index];
    }
    return number;
}

void DynamicArray::set(int index, int data)
{
    if(isRetrievable(index))
    {
        arr[index] = data;    
    }
    else
    {
        throw("Array Index out of Bounds.");
    }
    
}

void DynamicArray::growTable()
{
    int* temp = arr;
    length *= 2;
    arr = new int[length];
    for(int i = 0; i < arr_size; i++)
    {
        arr[i] = temp[i];
    }
    delete [] temp;
}

void DynamicArray::append(int data)
{
    if(length == arr_size)
    {
        growTable();
    }
    arr[arr_size] = data;
    arr_size++;
}

int DynamicArray::remove(int index)
{
    int original_data = -1;
    if(isRetrievable(index))
    {
        original_data = get(index);
        int * temp = new int[length];
        
        
        for (int i = index+1; i <= length; i++)
        {
            temp[i-1] = arr[i];
        }
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        arr_size = arr_size -1;
        arr = new int[arr_size];
        length = arr_size;
        for (int i = 0; i < arr_size; i++)
        {
            arr[i] = temp[i];
        }
        
        delete[] temp;
    }
    else
    {
        throw("Array Index out of Bounds.");
    }
    return original_data;
}

int DynamicArray::size()
{
    return length;
}

int DynamicArray::spaceFilled()
{
    return arr_size;
}

int* DynamicArray::statistics()
{
    int max = 0, sum = 0;
    double mean = 0;
    int min = INT16_MAX;
    int max_temp, min_temp = 0;
    for(int i = 0; i < arr_size; i++)
    {
        mean += arr[i];
        if(min > arr[i])
        {
            min = arr[i];
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Sum : " << mean << endl;

    mean /= arr_size;
    int * stats = new int[4];
    stats[0] = mean;
    stats[1] = min;
    stats[2] = max;
    stats[3] = sum;
    cout << "Mean : " << mean << endl;
    cout << "Min : " << min << endl;
    cout << "Max : " << max << endl;
    return stats;
}

void DynamicArray::printArray()
{
    for(int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << endl;
    }
}
#ifndef DynamicArray_H
#define DynamicArray_H

class DynamicArray
{
private:
    int* arr;
    int arr_size;
    int length;
    void growTable();
    bool isRetrievable(int index);
public:
    DynamicArray(int initial_size=2);
    int get(int index);
    void set(int index, int data);
    void append(int data);
    int remove(int index);
    int size();
    int* statistics(); //Returns the mean, max, and the minimum of the array.
    int spaceFilled(); // Return arr_size.
    void printArray();
};

#endif
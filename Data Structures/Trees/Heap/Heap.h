#ifndef Heap_H
#define Heap_H
#include <vector>
using namespace std;
/**
 * Binary Structurally Balanced Heap.
 * Priority Queue.
*/
class Heap
{
private:
    int * H; // array
    int siblings [2];
    int * temp; //temporary array
    int current_size; //latest accessible element of heap array H.
    int getParent(int index); //returns parent of element # index.
    int * getSiblings(int index); // returns at most 2 siblings corresponding to index.
    int * sort(int current_size); // run-time : O(n) reduced from O(n log(n)) using Heapify backward propogataion algorithm.
    int flag;
    vector<int> *arr;
public:
    Heap();
    int extractMax();
    void insert(int data);
    bool isEmpty();
    void remove(int index);
    int * getNodeInformation(int index);
    void printHeap();
};

#endif

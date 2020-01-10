#ifndef Heap_H
#define Heap_H
/**
 * Binary Structurally Balanced Heap.
 * Priority Queue.
*/
class Heap
{
private:
    int * H; // array
    int * temp; //temporary array
    int current_size; //latest accessible element of heap array H.
    int getParent(int index); //returns parent of element # index.
    int * getSiblings(int index); // returns at most 2 siblings corresponding to index.
    int * sort(int * arr, int current_size, bool flag);
    int flag;
    std::vector<int> arr;
public:
    Heap();
    ~Heap();
    int extractMax();
    void insert(int data); //<--
    bool isEmpty();
    void remove(int data); //<--
    int * getNodeInformation(int index);
    void shiftDown(int data, int index); //<--
    void shiftUp(int data, int index); //<--
    void printHeap();
};

#endif
#include "Heap.cpp"
using namespace std;

int main()
{
    bool checker;
    Heap heap;
    
    checker = heap.isEmpty();
    cout << checker << endl;
    
    heap.insert(40);
    
    checker = heap.isEmpty();
    cout << checker << endl;
    
    heap.insert(90);
    heap.insert(10);
    heap.insert(21);

    heap.printHeap();
    
    return 0;
}
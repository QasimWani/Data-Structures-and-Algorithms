#include "Heap.cpp"
using namespace std;

int main()
{
    Heap heap;

    int data;

    while (data != -1)
    {
        cout << "\nEnter data (-1 to Quit) : ";
        cin >> data;
        if(data != -1)
        {
            heap.insert(data);
        }
    }
    cout << "Printing Data...\n" << endl;
    heap.printHeap();
    int max = heap.extractMax();
    cout << "Heap Maximum element : " << max << endl;
    data = 0;
    while (data != -1)
    {
        cout << "\n Delete index (-1 to Quit) : ";
        cin >> data;
        if(data != -1)
        {
            heap.remove(data);
        }
    }
    cout << "Printing Data...\n" << endl;
    heap.printHeap();
    return 0;
}
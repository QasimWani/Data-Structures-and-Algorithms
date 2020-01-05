#include <cstdlib>
#include <iostream>
#include "../Linked List/Doubly/LinkedList.cpp"
#include <string>
using namespace std;

int main()
{
    LinkedList List;
    List.addNode(3); //EnQueue.
    List.addNode(6); //EnQueue.
    List.addNode(9); //EnQueue.

    List.printList();

    cout << "Enqueue Completed." << endl;

    int dequeue = List.popFront(); //Dequeue.
    List.printList();
    cout << "Element Dequeued : " << dequeue << endl;
    return 0;
}
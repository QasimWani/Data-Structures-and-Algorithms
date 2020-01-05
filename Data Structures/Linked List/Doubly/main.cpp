#include <cstdlib>
#include "LinkedList.cpp"
#include <iostream>
using namespace std;

int main()
{
    LinkedList List;
    List.addNode(3);
    List.addNode(6);
    List.addNode(9);
    List.printList();

    cout <<"\n"<<endl;

    int num = List.popEnd(); 
    cout << "POPPED."<< num << endl;
    List.addNode(12);
    List.reverseList();
    cout << "Reversed." << endl;
    // List.addNode(162);
    // List.reverseList();
    // List.deleteNode(6);
    // List.deleteNode(2);
    // List.printList();
    // int pop_result = List.popFront();
    // cout << pop_result << endl;
    // cout << "Pop = Success." << endl;
    // List.printList();
    
    // bool status = List.isEmpty();
    // cout << "Current List status : " << status << endl;
    // List.deleteList();
    // List.printList();
    // status = List.isEmpty();
    // cout << "List == Empty : " << status << endl;
    return 0;
}
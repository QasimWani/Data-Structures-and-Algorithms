
#ifndef Linked_List
#define Linked_List
class LinkedList
{
private:
    typedef struct node
    {
        int data;
        node* next;
        node* previous;
    }* nodePtr;
    
    nodePtr head;
    nodePtr current;
    nodePtr temp;
    nodePtr tail;

public:
    LinkedList();
    void addNode(int addData); //Adds a node to the tail. Updates tail pointer reference assignment. O(1) run-time.
    void deleteNode(int deletedata); //Deletes a node with specific value. O(n) run-time.
    void printList(); //Prints all the node values. O(n) run-time.
    void pushFront(int addData); //Adds new node to the front. O(1) run-time.
    int popFront(); //Returns the node data pointing to the head and removes the head node. changes head pointer to next node. O(1) run-time
    int popEnd(); // Returns node data pointing to the tail. Removes the node. changes tail pointer to previous node. O(1) runtime.
    bool isEmpty(); //Returns true if LinkedList is empty, i.e. head points to nullPtr. O(1) run-time.
    void deleteList(); //Deletes the entire List from memory. Utilizes popFront(). O(n) runtime complexity.
    void reverseList(); //Reverses linked list.
};
#endif

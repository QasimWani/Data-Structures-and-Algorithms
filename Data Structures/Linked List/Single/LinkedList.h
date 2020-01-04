
#ifndef mains
#define mains
class LinkedList
{
private:
    typedef struct node
    {
        int data;
        node* next;
    }* nodePtr;
    
    nodePtr head;
    nodePtr current;
    nodePtr temp;

public:
    LinkedList();
    void addNode(int addData);
    void deleteNode(int deletedata);
    void printList();
};
#endif

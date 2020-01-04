#include <iostream>
#include <cstdlib>

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    current = NULL;
    temp = NULL;
}
void LinkedList::addNode(int addData)
{
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;
    if(head != NULL)
    {
        current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    else
    {
        head = n;
    }
    
}


void LinkedList::deleteNode(int deleteData)
{
    nodePtr d = NULL;
    temp = head;
    current = head;
    while(current != NULL && current->data != deleteData)
    {
        temp = current;
        current = current->next;
    }
    
    if(temp->next == NULL)
    {
        cout << deleteData << " not found in the List." << endl;
        delete d;
    }
    else
    {
        d = current; 
        current = current->next;   
        temp->next = current;
        delete d;
    }
}

void LinkedList::printList()
{
    current = head;
    while(current != NULL)
    {
        cout << current->data  << endl;
        current = current->next;
    }
}
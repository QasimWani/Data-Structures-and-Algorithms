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

void LinkedList::pushFront(int data)
{
    temp = head;
    nodePtr pf = new node;
    pf->data = data;
    pf->next = temp;
    head = pf;    
}

int LinkedList::popFront()
{
    temp = head;
    nodePtr top = temp;
    if(isEmpty())
    {
        cout << "List is Empty. Nothing to pop" << endl;
        return -1;
    }
    int data = top->data;
    temp = top->next;
    head = temp;
    delete top;
    
    return data;
}

int LinkedList::popEnd()
{
    if(isEmpty())
    {
        cout << "List is empty. Nothing to pop at rail." << endl;
        return -1;
    }
    nodePtr del = head;

    while(del->next != NULL)
    {
        temp = del;
        del = del->next;
    }
    int data = del->data;
    temp->next = NULL;
    delete del;
    return data;
}

bool LinkedList::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

void LinkedList::deleteList()
{
    if(!isEmpty())
    {
        while(!isEmpty())
        {
            popFront();
        }
        cout << "List cleared." << endl;
    }
    else
    {
        cout << "List already Empty." << endl;
    }
    
}
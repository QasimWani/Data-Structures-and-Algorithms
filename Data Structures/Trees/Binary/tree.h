#ifndef Tree_H
#define Tree_H
class Tree
{
private:
    typedef struct node
    {
        int data;
        node* left;
        node* right;
    }* nodePtr;
    nodePtr root;
    nodePtr temp;
    nodePtr current;

public:
    Tree();
    void newNode(int data);
    nodePtr insertOne(nodePtr position, int data);
    bool isEmpty();
    int getNode(nodePtr element);
    void printTree();
    
};

#endif
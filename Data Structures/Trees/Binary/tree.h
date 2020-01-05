#ifndef Tree_H
#define Tree_H

template<class T>

class Tree
{
private:
    typedef struct node
    {
        T data;
        node* left;
        node* right;
    }* nodePtr;
    nodePtr root;
    nodePtr temp;
    nodePtr current;

public:
    Tree();
    
    void addChild(T data, node position);
    
    bool isEmpty();
    T getNode(node element);
};

#endif
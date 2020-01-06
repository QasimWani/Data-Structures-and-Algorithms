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
    
public:
    nodePtr root;
    nodePtr temp;
    nodePtr current;
    Tree();
    nodePtr newNode(nodePtr rootNode, int data);
    bool isEmpty();
    nodePtr getNode(int data);
    bool printTree(nodePtr tree_structure, int data);
};

#endif
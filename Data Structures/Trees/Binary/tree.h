#ifndef Tree_H
#define Tree_H
template<typename T>
class tree
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
    tree();
    void addChild(T node);
};

#endif
#include <cstdlib>
#include "LinkedList.cpp"

using namespace std;

int main()
{
    LinkedList List;
    List.addNode(3);
    List.addNode(6);
    List.addNode(9);
    List.printList();
    List.deleteNode(6);
    List.deleteNode(2);
    List.printList();
    return 0;
}
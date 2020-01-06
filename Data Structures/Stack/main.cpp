#include <cstdlib>
#include <iostream>
#include "../Linked List/Single/LinkedList.cpp"
#include <string>
using namespace std;

int main()
{
    string data;
    cout << "Enter String to check if it's balanced : ";
    cin >> data;
    int size = data.length();
    int current_element;
    int ascii_value;
    if(data[0] == '}' || data[0] == ')' || data[0] == ']')
    {
        cout << "Can't start with a closure." << endl;
        return -1;
    }
    LinkedList *Stack = new LinkedList();
    for(int i = 0; i < size; i++)
    {
        current_element = int(data[i]);

        if(Stack->isEmpty())
        {
            Stack->addNode(current_element);
        }
        else
        {
            ascii_value =  Stack->seeStack();
            if(abs(ascii_value - current_element) <= 2)
            {
                Stack->popFront();//Stack closed
            }
            else
            {
                Stack->pushFront(current_element);
            }
        }
    }
    if(Stack->isEmpty())
    {
        cout << "String is balanced." << endl;
        return 1;
    }
    cout << "String unbalanced." << endl;
    return 0;
}
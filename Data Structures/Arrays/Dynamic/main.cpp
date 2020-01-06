#include "DynamicArray.cpp"
#include <iostream>

using namespace std;


int main()
{
    int size;
    
    DynamicArray Vector;
    int quit;
    do
    {
        cout << "\nAppend Data to Vector (-1 to Quit) : ";
        cin >> quit;
        if(quit != -1)
        {
            Vector.append(quit);
        }
    } while (quit != -1);
    
    cout << "**************************\n"<<endl;
    
    Vector.printArray();
    size = Vector.size();
    cout << "Vector Size : " << size << endl;
    size = Vector.spaceFilled();
    cout << "Vector Space Filled : " << size << endl;
    int * statistics = Vector.statistics();
    
    cout << "**************************\n"<<endl;

    quit = 0;

    while (quit != -1)
    {
        size = Vector.size() - 1;
        cout << "Element [index] to remove [0 : " << size <<"] (-1 to Quit): ";
        cin >> quit;
        if(quit != -1)
        {
            int num = Vector.remove(quit);
            cout << "Retrieved Number : " << num << endl;
        }
    }
    cout << "**************************\n"<<endl;
    
    Vector.printArray();
    size = Vector.size();
    cout << "Vector Size : " << size << endl;
    size = Vector.spaceFilled();
    cout << "Vector Space Filled : " << size << endl;
    Vector.statistics();
    
    cout << "**************************\n"<<endl;
    return 0;
}
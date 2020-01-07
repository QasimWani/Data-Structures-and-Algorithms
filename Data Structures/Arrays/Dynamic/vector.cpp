#include <cstdlib>
#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    vector<int> vec;
    int data;
    while (data != -1)
    {
        cout << "\nEnter data: ";
        cin >> data;
        vec.push_back(data);
    }
    auto i = vec.begin();
    // i++;
    printf("Address of x is %p\n", (void *)&*i);  

    cout << &*i << endl;
    i++;
    cout << &*i << endl;
    printf("Address of x is %p\n", (void *)&*i);  
    return 0;
}
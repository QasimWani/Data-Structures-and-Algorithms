#include "Hash.cpp"
#include <iostream>
#include <cstdlib>
#include <istream>
#include <time.h>
using namespace std;

int main()
{
    Hash * phone = new Hash();
    long long number;
    string contactName;
    clock_t t1,t2;
    float diff;
    while (number != -1)
    {
        cout << "\nEnter Phone Number : ";
        cin >> number;
        cin.ignore();
        if (number != -1)
        {
            cout << "\nEnter Contact Name : ";
            getline(cin, contactName);
            phone->addHash(number, contactName);
        }
    }
    
    cout << "\nPrinting Name Based Hash Table\n" << endl;
    t1 = clock();
    phone->printNumHash();
    t2 = clock();
    
    cout << "\nPrinting Number Based Hash Table\n" << endl;

    phone->printNameHash();

    cout << "\nSearching : " << endl;
    cout << "Find One Contact by Name: ";
    getline(cin, contactName);
    phone->findByName(contactName, true);
    cout << "Find One Contact by Number: ";
    cin >> number;
    phone->findByNumber(number, true);

    diff = ((float)t2-(float)t1);
    cout<< "\n\nTime Difference : " << diff << "\n" << endl;

    
    return 0;
}
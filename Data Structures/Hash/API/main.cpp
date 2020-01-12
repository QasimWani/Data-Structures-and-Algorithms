#include "Hash.cpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    Hash * phone = new Hash();
    long long number;
    char contactName [200];
    // for(int i = 0; i < 10; i++)
    // {
    //     cout << "\nEnter Phone Number (-1 to Quit): ";
    //     cin >> number;
    //     cout << "\nContact Name: ";
    //     cin >> contactName;
    //     cout << number << " " << contactName << endl;
    //     phone->addHash(number, contactName);
    // }
    phone->addHash(15409985673, "Qasim Wani");
    phone->addHash(12345678901, "Foo bar");
    phone->addHash(12343561421, "John Doe");

    cout << "\nPrinting Name Based Hash Table\n" << endl;
    phone->printNameHash();
    cout << "\nPrinting Number Based Hash Table\n" << endl;
    phone->printNumHash();
    phone->findByName("Foo bar");

    return 0;
}
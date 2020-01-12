#ifndef Hash_H
#define Hash_H
#include <list>
#include <iostream>

using namespace std;
class Hash
{
private:
    /* data */
    typedef struct contact
    {
        long long number;
        string contact;
    } * contactPtr;
    int A;
    int B;
    long P;
    int M;
    contactPtr temp;
    list<contactPtr> * numHash;
    list<contactPtr> * nameHash;
    
    int get_int_Hash(long long data);//Hash function for type Int.
    int get_str_Hash(string data, int X);//Hash function for type String.
public:
    Hash();
    contactPtr findByNumber(long long data, bool state);
    contactPtr findByName(string data, bool state);
    void addHash(long long number, string name);
    void printNumHash();
    void printNameHash();
    void removeHashedElement(long long number, string name);
    bool isEmpty();
};



#endif
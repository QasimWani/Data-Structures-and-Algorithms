#include <string>
#include <iostream>
#include <cstdlib>
#include "Hash.h"

using namespace std;

Hash::Hash()
{
    A = 34;
    B = 1;
    P = long(10000019);
    M = 1000;
    temp = NULL;
    numHash = new list<contactPtr>[M];
    nameHash = new list<contactPtr>[M];
}

int Hash::get_int_Hash(long long data)
{
    int hashed = (((A*data) + B)%P)%M;
    return hashed;
}

int Hash::get_str_Hash(string data, int X)
{
    int hash = 0;
    for (int i = data.length()-1; i >= 0; i--)
    {
        hash += (hash*X + int(data[i]))%P;
    }
    
    return hash%M;
}

void Hash::removeHashedElement(long long number, string name)
{
    temp = findByNumber(number);
    if(temp != NULL)
    {
        int hashNum = get_int_Hash(number);
        int hashName = get_str_Hash(name, 31);

        numHash[hashNum].remove(temp);
        temp = findByName(name);
        nameHash[hashName].remove(temp);
    }
    else
    {
        cout << "Contact, " << name << ", does not exist." << endl;
    }
    
}

void Hash::addHash(long long num, string name)
{
    if(findByNumber(num) == NULL)
    {
        int hashNum = get_int_Hash(num);
        int hashName = get_str_Hash(name, 31);
        contactPtr n = new contact;
        n->contact = name;
        n->number = num;
        temp = n;
        temp->contact = name;
        temp->number = num;
        numHash[hashNum].push_back(temp);
        nameHash[hashName].push_back(temp);
    }
    else
    {
        cout << "Contact, "<< name <<", already exists." << endl;
    }
    
}

Hash:: contactPtr Hash::findByNumber(long long data)
{
    int hash = get_int_Hash(data);

    if(numHash[hash].empty())
    {
        return NULL;
    }
    contactPtr ptr = *numHash[hash].begin();
    while (ptr->number != data)
    {
        temp = ptr;
        ptr++;
    }
    return temp;
}

Hash:: contactPtr Hash::findByName(string data)
{
    int hash = get_str_Hash(data, 31);

    if(nameHash[hash].empty())
    {
        return NULL;
    }
    contactPtr ptr = new contact;
    temp = new contact;
    temp = *numHash[hash].begin();

    while (temp->contact != data)
    {
        ptr = temp;
        temp++;
    }

    return ptr;
}

void Hash::printNameHash()
{
    for (int i = 0; i < M; i++)
    {
        if (!nameHash[i].empty())
        {
            contactPtr records = *nameHash[i].begin();
            for (int j = 0; j < nameHash[i].size(); j++)
            {
                cout << i << ". " << records->contact << "\t" << records->number << endl;
                records++;
            }           
        }
        
    }
    
}

void Hash::printNumHash()
{
    for (int i = 0; i < M; i++)
    {
        if (!numHash[i].empty())
        {
            contactPtr records = *numHash[i].begin();
            for (int j = 0; j < numHash[i].size(); j++)
            {
                cout << i << ". " << records->contact << "\t" << records->number << endl;
                records++;
            }      
            
        }
        
    }
    
}

bool Hash::isEmpty()
{
    if(temp == NULL)
    {
        return true;
    }
    return false;
}
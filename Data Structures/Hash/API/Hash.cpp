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
    if(findByNumber(number, false) != NULL && findByName(name, false) != NULL)
    {
        int hashNum = get_int_Hash(number);
        int hashName = get_str_Hash(name, 31);
        numHash[hashNum].remove(findByNumber(number, false));
        nameHash[hashName].remove(findByName(name, false));
    }
    else
    {
        cout << "Contact, \"" << name << "\"; Phone : \"" << number << "\" does not exist." << endl;
    }
    
}

void Hash::addHash(long long num, string name)
{
    if(findByNumber(num, false) == NULL)
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

Hash:: contactPtr Hash::findByNumber(long long data, bool state)
{
    int hash = get_int_Hash(data);
    if(numHash[hash].empty())
    {
        if (state)
        {
            cout << "\nNumber does not exist in directory." << endl;
        }
        return NULL;
    }
    contactPtr ptr = NULL;
    for (list<contactPtr>::iterator i = numHash[hash].begin(); i != numHash[hash].end(); i++)
    {
        temp = contactPtr(*i);
        if (temp->number == data)
        {
            ptr = temp;
            break;
        }
    }
    if (state)
    {
        cout << "\nName : \"" << temp->contact << "\"\tNumber : " << temp->number << endl;
    }
    return ptr;
}

Hash:: contactPtr Hash::findByName(string data, bool state)
{
    int hash = get_str_Hash(data, 31);

    if(nameHash[hash].empty())
    {
        if (state)
        {
            cout << "\nName does not exist in directory." << endl;
        }
        return NULL;
    }
    
    contactPtr ptr = NULL;
    
    for (list<contactPtr>::iterator i = nameHash[hash].begin(); i != nameHash[hash].end(); ++i)
    {
        temp = contactPtr(*i);
        if (temp->contact == data)
        {
            ptr = temp;
            break;
        }    
    }
    if (state)
    {
        cout << "\nName : \"" << temp->contact << "\"\tNumber : " << temp->number << endl;
    }
    
    return temp;
}

void Hash::printNameHash()
{
    for (int i = 0; i < M; i++)
    {
        if (!nameHash[i].empty())
        {
            for (list<contactPtr>::iterator j = nameHash[i].begin(); j != nameHash[i].end(); ++j)
            {
                cout << i << ". " << contactPtr(*j)->contact << "\t" << contactPtr(*j)->number << endl;
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
            for (list<contactPtr>::iterator j = numHash[i].begin(); j != numHash[i].end(); ++j)
            {
                cout << i << ". " << contactPtr(*j)->contact << "\t" << contactPtr(*j)->number << endl;
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
#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
using namespace std;


auto sort_array(vector<int> vec, int data)
{
    int half = vec.size()/2;
    auto ptr = vec.begin();
    auto z = array<int, 2>{};
    z[0] = half;
    z[1] = *ptr;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(5);
    auto ptr = vec.begin();
    for (int i = 0; i < vec.size(); i++)
    {
        cout << *ptr << endl;
        ptr++;
    }
    int half = vec.size() / 2;
    ptr = vec.begin();
    return 0;
}
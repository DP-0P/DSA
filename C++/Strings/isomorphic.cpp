#include<iostream>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;

    int a1[256] = {0};
    int a2[256] = {0};

    for (int i = 0; i < str1.size(); i++)
    {
        a1[str1[i]]++;
        a2[str2[i]]++;
    }

    for (int i = 0; i < str2.size(); i++)
        if (a1[str1[i]] != a2[str2[i]])
            return false;
    return true;
}
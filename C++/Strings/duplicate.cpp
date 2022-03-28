#include <iostream>
#include <unordered_map>
using namespace std;

void duplicate(string s)
{
    int array[52] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[i] - 'A';
        array[temp]++;
    }

    for (int i = 0; i < 52; i++)
        if (array[i] > 0)
            cout << char(i + 'A') << " count = " << array[i] << " | ";
}

void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;
  
    for (auto it : count)
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << "\n";
}

int main()
{
    duplicate("geeksforgeeks");
    printDups("geeksforgeeks");
}
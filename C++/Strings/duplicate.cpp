#include <iostream>
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

int main()
{
    // char c='a';
    // cout<<(char)(c+5)<<endl;
    duplicate("geeksforgeeks");
}
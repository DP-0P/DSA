#include <iostream>
using namespace std;

void permu(string str, int index)
{
    if (index == str.length())
    {
        cout << str << endl;
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        permu(str, index + 1);
        swap(str[index], str[i]);
    }
}

int main()
{
    permu("abc", 0);
    // string a = "abc";
    // swap(a[0],a[0]);
    // cout<<a;
}
#include <iostream>
using namespace std;

void findMaxUtil(string str, string &max, int k, int pos)
{
    if (k == 0)
        return;

    char maxm = str[pos];
    for (int i = pos + 1; i < str.length(); i++)
        if (maxm < str[i])
            maxm = str[i];

    if (maxm != str[pos])
        k--;

    for (int i = str.length() - 1; i >= pos; i--)
        if (str[i] == maxm)
        {
            swap(str[i], str[pos]);
            if (str.compare(max) > 0)
                max = str;

            findMaxUtil(str, max, k, pos + 1);

            swap(str[i], str[pos]);
        }
}

int main()
{
    string str = "1234567";
    string max = str;
    int k = 4;
    cout << max << endl;
    findMaxUtil(str, max, k, 0);
    cout << max;
}

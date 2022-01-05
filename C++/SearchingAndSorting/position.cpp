#include <iostream>
using namespace std;

int main()
{
    int x = 5;

    int array[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    int first = INT_MAX, last = INT_MIN;

    for (int i = 0; i < 9; i++)
        if (array[i] == x)
        {
            if (i < first)
                first = i;

            if (i > last)
                last = i;
        }

    cout << "First Occurenece is at " << first << endl;
    cout << "Last Occurenece is at " << last << endl;
}
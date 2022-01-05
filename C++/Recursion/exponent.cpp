#include <iostream>
using namespace std;

int exp(int n, int e)
{
    if (e == 0)
        return 1;

    return n * exp(n, e - 1);
}

int fastExp(int n)
{
    if (n == 0)
        return 1;

    int base = fastExp(n / 2);

    if (n % 2 == 0)
        return base * base;
    else
        return 2 * base * base;
}

int main()
{
    cout << fastExp(5);
}
#include <iostream>
using namespace std;

int mul = 1;
int factorial(int n)
{
    if (n == 0)
        return 1;

    // mul = n * factorial(n-1);

    return n * factorial(n - 1);
}

int main()
{
    cout << factorial(3);
}
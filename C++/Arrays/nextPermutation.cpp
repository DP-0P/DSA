#include <iostream>
using namespace std;

void nextPermutation(int array[], int length)
{
    int k = -1;
    for (int i = length - 1; i > 0; i--)
        if (array[i] > array[i - 1])
        {
            k = i;
            break;
        }

    if (k == -1)
    {
        int start = 0;
        int end = length-1;
        while (end > start)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }

    else
    {
        int prev = k;
        for (int i = k + 1; i < length; i++)
            if (array[i] > array[k - 1] and array[i] <= array[prev])
                prev = i;

        int temp = array[prev];
        array[prev] = array[k - 1];
        array[k - 1] = temp;

        int start = k;
        int end = length-1;
        while (end > start)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
    for (int i = 0; i < length; i++)
        cout << array[i] << " ";
}

int main()
{
    int array[] = {1,2,3};
    int length = sizeof(array) / sizeof(array[0]);
    nextPermutation(array, length);
}
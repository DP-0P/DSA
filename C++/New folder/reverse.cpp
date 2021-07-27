#include <iostream>
using namespace std;

void reverse(int array[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(array) / sizeof(array[0]);
    cout << size<<endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    reverse(array, size);
    cout<<endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    return 0;
}

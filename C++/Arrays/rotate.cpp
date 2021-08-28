#include <iostream>
using namespace std;

void rotateClockwise(int arr[], int n)
{
    int temp = arr[n - 1];
    int j = n - 2;
    for (int i = n - 1; i >= 1; i--)
        arr[i] = arr[j--];
    arr[0] = temp;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void rotateAntiClockwise(int arr[], int n)
{
    int temp = arr[0];
    int j = 1;
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[j++];
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    rotateClockwise(arr, 5);
    cout<<endl;
    rotateAntiClockwise(arr, 5);
}
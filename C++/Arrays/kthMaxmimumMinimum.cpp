#include <iostream>
using namespace std;

void kthElement(int array[], int size, int k)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "Kth largest element : " << array[k + 1] << endl;
    cout << "Kth smallest element : " << array[k - 1];
}
int main()
{
    int array[] = {6, 4, 5, 2, 1, 3};
    int size = sizeof(array) / sizeof(array[0]);
    kthElement(array, size, 2);
    return 0;
}
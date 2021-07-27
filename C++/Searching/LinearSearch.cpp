#include <iostream>
using namespace std;

void search(int array[], int size, int search)
{
	int index = -1;
	for (int i = 0; i < size; i++)
		if (array[i] == search)
			index = i;

	if (index < 0)
		cout << "Searched element is not available in array";
	else
		cout << "Searched element is present at index " << index;
}

int main()
{
	int arr[] = {2, 3, 4, 10, 40};
	int x = 1;
	int n = *(&arr + 1) - arr;

	search(arr, n, x);

	return 0;
}

// Time Complexity -
// Best Case - O(1)
// Worst Case - O(n)
// Average Case - O(n/2)

// Space complexity - O(1)
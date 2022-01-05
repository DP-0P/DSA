#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int> array, int target)
{
    int low = 0, high = array.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == target)
            return mid;

        if (array[low] <= array[mid])
        {
            if (target >= array[low] and target < array[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        else
        {
            if (target > array[mid] and target < array[high])
                low = mid+1;
            else
                high = mid -1 ;
        }
    }
    return -1;
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    cout<<searchInRotatedSortedArray(vec,4);
}
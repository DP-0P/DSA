#include <iostream>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    // code here
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j=i+1; j < n;j++)
        {
            if (arr[i] + arr[j] == k)
                c++;
        }
    }
    return c;
}

int main(){
    int arr[] = {1, 1, 1, 1};
    cout<<getPairsCount(arr,4,2);
}
#include<iostream>
#include<unordered_set>
using namespace std;

bool subArrayExists(int arr[],int n){

    unordered_set<int> sett;
    int sum=0;

    for(auto i=0;i<n;i++){
        
        sum+=arr[i];
        sett.insert(sum);

        if(sum==0 || sett.find(sum) != sett.end())
            return 1;
    }
    return 0;
}

int main(){
    int arr[] = { 4,2,-3,1,6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
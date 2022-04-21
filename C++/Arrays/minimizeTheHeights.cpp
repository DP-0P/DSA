#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int res = arr[n-1]-arr[0];
    int minRes = arr[0];
    int maxRes = arr[n-1];
    for(int i=1;i<n;i++){
        minRes = min(arr[0]+k,arr[i]-k);
        maxRes = max(arr[i-1]+k,arr[n-1]-k);
            
        if(minRes<0)
            continue;
                
        res = min(res,maxRes-minRes);
    }
    return res;
}

int main(){
    int arr[] = {1, 5, 8, 10};
    cout<<getMinDiff(arr,4,2);
}
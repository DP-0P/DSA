#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Kclosest(vector<int>arr, int n, int x, int k){ 
    priority_queue<pair<int,int>>maxHeap;
    vector<int> res;

    for(int i=0;i<n;i++){
        maxHeap.push({abs(arr[i]-x),arr[i]});
        if(maxHeap.size()>k)
        maxHeap.pop();
    }

    while(maxHeap.size()>0){
        int temp=maxHeap.top().second;
        res.push_back(temp);
        maxHeap.pop();
    }

    sort(res.begin(),res.end());
    return res;
}

int main(){
    
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void mergeKSortedArrays(vector<vector<int>> nums,int k){
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> maxHeap;
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            maxHeap.push(nums[i][j]);
    
    while(!maxHeap.empty()){
        res.push_back(maxHeap.top());
        maxHeap.pop();
    }

    for(auto i:res)
        cout<<i<<" ";
}

int main(){
    vector<vector<int>> num = {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    mergeKSortedArrays(num,4);
}
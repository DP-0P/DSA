#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maximumSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> pq;
    priority_queue<int,vector<int>,greater<int>> temp;
    for(int i=0;i<k;i++)
        pq.push(nums[i]);
        
    res.push_back(pq.top());
    for(int i=k;i<nums.size();i++){
        if(nums[i-k]==pq.top())
            pq.pop();

        else
            temp.push(nums[i-k]);

        pq.push(nums[i]);
        while(!temp.empty() && pq.top()==temp.top()){
            pq.pop();
            temp.pop();
        }
        res.push_back(pq.top());
    }
    return res;
}

int main(){
    vector<int> num = {1,3,-1,-3,5,3,6,7};
    num = maximumSlidingWindow(num,3);
    for(auto i:num)
        cout<<i<<" ";
}
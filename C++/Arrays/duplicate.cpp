#include<iostream>
using namespace std;
#include<vector>

int duplicate(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        int temp = nums[i];
        for(int j=0;j<nums.size();j++)
            if(temp == nums[j] and j!=i)
                return temp;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,1,2};
    cout<<duplicate(arr);
}
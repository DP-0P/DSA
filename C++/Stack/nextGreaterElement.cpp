#include <iostream>
using namespace std;
#include <vector>
#include <stack>

vector<int> nextGreaterElementsRight(vector<int>& nums){
    stack<int> st;
    vector<int> nge(nums.size(),-1);
    for(int i=2*nums.size()-1;i>=0;i--){
        while(!st.empty() and st.top()<=nums[i%nums.size()])
            st.pop();
        if(i<nums.size()){
            if(!st.empty())
                nge[i] = st.top();
            else
                nge[i] = -1;
        }
        st.push(nums[i%nums.size()]);
    }
    return nge;
}

vector<int> nextGreaterElementsLeft(vector<int>& nums){
    stack<int> st;
    vector<int> nge(nums.size(),-1);
    for(int i=0;i<2*nums.size();i++){
        while(!st.empty() and st.top()<=nums[i%nums.size()])
            st.pop();
        if(i>=nums.size()){
            if(!st.empty())
                nge[i%nums.size()] = st.top();
            else
                nge[i%nums.size()] = -1;
        }
        st.push(nums[i%nums.size()]);
    }
    return nge;
}

int main(){
    vector<int> v = {1,2,3,4,3};
    vector<int> nge = nextGreaterElementsRight(v);
    for(int i=0;i<nge.size();i++)
        cout<<nge[i]<<" ";
    cout<<endl;
    nge = nextGreaterElementsLeft(v);
    for(int i=0;i<nge.size();i++)
        cout<<nge[i]<<" ";
}
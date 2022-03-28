#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> nums){
    stack<pair<int,int>> st;
    vector<int> nge(nums.size(),-1);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() and st.top().first<=nums[i])
            st.pop();
        if(!st.empty())
            nge[i] = st.top().second;
        else
            nge[i] = -1;
        st.push({nums[i],i});
    }
    for(int i=0;i<nge.size();i++)
        nge[i] = i - nge[i];
    return nge;
}

int main(){
    vector<int> stocks = {100,80,60,70,60,75,85};
    vector<int> res = stockSpan(stocks);
    for(int i=0;i<stocks.size();i++)
        cout<<res[i]<<" ";
}
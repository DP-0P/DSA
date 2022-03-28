#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> ms;
    int ans = 0;
    int n = heights.size();    
    for(int i = 0; i < n; i++){        
        while(!ms.empty() and heights[ms.top()] > heights[i]){
            int height = heights[ms.top()];
            ms.pop();
            int width = ms.empty() ? i : i - ms.top() - 1;
            ans = max(ans, height * width);
            cout<<ans<<" "<<height<<" "<<width<<endl;
        }
        ms.push(i);
    }    
    return ans;
}

int main(){
    vector<int> height = {6,2,5,4,5,1,6};
    cout<<largestRectangleArea(height);
}
int trap(vector<int>& height) {
    int n = height.size(),ans=0;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && height[st.top()] < height[i])
        {
            int curr=st.top();
            st.pop();
            if(!st.empty())
            {
                int len=i-st.top()-1;
                ans += (min(height[i],height[st.top()])-height[curr])*len;
            }
        }
        st.push(i);
    }
    return ans;
}
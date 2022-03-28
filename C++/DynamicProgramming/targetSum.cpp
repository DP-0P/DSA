#include<iostream>
#include<vector>
using namespace std;

int targetSum(vector<int> vec,int target){
    int sum=0;
    for(auto i:vec)
        sum+=i;
    if(sum<target or (sum+target)%2)
        return 0;
    
    int s = (sum+target)/2;
    int dp[vec.size()][s+1];
    for(int i=0;i<=vec.size();i++)
        dp[i][0] = 1;
    for(int i=1;i<=s;i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=vec.size();i++){
            for(int j=0;j<=s;j++){
                
                if(vec[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-vec[i-1]];
            }
        }
        return dp[vec.size()][s];
}

int main(){
    vector<int> vec = {1,1,1,1,1};
    cout<<targetSum(vec,3);
}
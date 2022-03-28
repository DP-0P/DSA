#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//check later
int unboundedKnapsack(int w,int wt[],int val[],int n){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 or j==0)
                dp[i][j] = 0;
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);   
        }
    }
    return dp[n][w];
}

int main()
{
    int n = 4;
    int w = 8;
    int values[] = {10, 40, 50, 70};
    int weight[] = {1, 3, 4, 5};
    int dp[6][10];
    memset(dp, -1, sizeof(dp));
    cout<<unboundedKnapsack(w,weight,values,n)<<endl;
}
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//will change accordingly 
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
    int n = 8;
    int w = 8;
    int values[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int weight[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int dp[6][10];
    memset(dp, -1, sizeof(dp));
    cout<<unboundedKnapsack(w,weight,values,n)<<endl;
}
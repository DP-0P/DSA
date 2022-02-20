#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int knapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] > w)
        return knapsack(w, wt, val, n - 1);

    else
        return max(val[n - 1] + knapsack(w - wt[n - 1], wt, val, n - 1), knapsack(w, wt, val, n - 1));
}

//memoization
// int dp[6][6];
int knapsackMemoization(int w, int wt[],int dp[6][10], int val[], int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] > w)
        return dp[n][w] = knapsackMemoization(w, wt,dp, val, n - 1);

    else
        return dp[n][w] = max(val[n - 1] + knapsackMemoization(w - wt[n - 1], wt,dp, val, n - 1), knapsackMemoization(w, wt,dp, val, n - 1));
}

//bottomUp
int knapsackBottomUp(int w,int wt[],int val[],int n){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 or j==0)
                dp[i][j] = 0;
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);   
        }
    }
    return dp[n][w];
}

int main()
{
    int n = 4;
    int w = 10;
    int values[] = {42, 12, 40, 25};
    int weight[] = {7, 3, 4, 5};
    int dp[6][10];
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(w,weight,values,n)<<endl;
    cout << knapsackMemoization(w, weight,dp, values, n) << endl;
    cout<<knapsackBottomUp(w,weight,values,n)<<endl;
}
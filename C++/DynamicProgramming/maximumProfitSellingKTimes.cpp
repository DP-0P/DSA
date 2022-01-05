#include <iostream>
using namespace std;
#include <cstring>

int maxProfit(int K, int N, int A[])
{
    int dp[K + 1][N];
    memset(dp, 0, sizeof(dp));
    for (auto i = 1; i <= K; i++)
    {
        int maxNum = INT_MIN;
        for (auto j = 1; j < N; j++)
        {
            maxNum = max(maxNum, dp[i - 1][j - 1] - A[j - 1]);
            dp[i][j] = max(dp[i][j - 1], maxNum + A[j]);
        }
    }
    return dp[K][N - 1];
}

int main()
{
    int k = 2;
    int n = 6;
    int array[] = {10, 22, 5, 75, 65, 80};
    cout<<maxProfit(k,n,array);
}
#include <iostream>
using namespace std;

int subsetCount(int array[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
    for(int i=1;i<=sum;i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (array[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            if (array[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - array[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    int array[] = {2,3,5,6,8,10};
    int n = sizeof(array) / sizeof(array[0]);
    int sum = 10;
    cout << subsetCount(array, sum, 6) << endl;
}

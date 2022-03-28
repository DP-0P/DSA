#include <iostream>
using namespace std;

bool subsetSum(int array[], int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (array[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            if (array[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - array[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    int array[] = {2, 3, 7, 8, 10};
    int n = sizeof(array) / sizeof(array[0]);
    int sum = 11;
    cout << subsetSum(array, sum, n) << endl;
}

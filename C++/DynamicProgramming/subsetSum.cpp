#include <iostream>
using namespace std;

bool subsetSum(int array[], int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = false;
            if (i == 0 and j == 0)
                dp[i][j] = true;
        }
    }

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
    int sum = 14;
    cout << subsetSum(array, sum, n) << endl;
}
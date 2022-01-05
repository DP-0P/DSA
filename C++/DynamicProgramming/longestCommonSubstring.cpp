#include <iostream>
using namespace std;

int longestCommonSubstring(string s1, string s2, int n, int m)
{
    int res = 0;
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    return res;
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "acdghr";
    cout << longestCommonSubstring(s1, s2, s1.size(), s2.size());
}
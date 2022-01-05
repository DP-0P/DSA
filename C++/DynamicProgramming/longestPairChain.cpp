#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int findLongestChain(vector<vector<int>> &pairs)
{
    if (pairs.size() == 0)
        return 0;

    if (pairs.size() == 1)
        return 1;

    sort(pairs.begin(), pairs.end());

    vector<int> dp(pairs.size(), 0);
    dp[0] = 1;

    for (auto i = 1; i < pairs.size(); i++)
    {
        dp[i] = 1;
        for (auto j = 0; j < i; j++)
            if (pairs[i][0] > pairs[j][1])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    return dp[pairs.size() - 1];
}

int main()
{
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << findLongestChain(pairs);
}
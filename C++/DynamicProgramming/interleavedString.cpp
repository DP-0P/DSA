#include <iostream>
using namespace std;

bool isInterleave(string A, string B, string C)
{
    int x = A.size();
    int y = B.size();
    int z = C.size();

    if (z != x + y)
        return false;

    bool dp[x + 1][y + 1];
    for (auto i = 0; i <= x; i++)
        for (auto j = 0; j <= y; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = (dp[i][j - 1] && B[j - 1] == C[i + j - 1]);
            else if (j == 0)
                dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i + j - 1]);
            else
                dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i - 1 + j] || dp[i][j - 1] && B[j - 1] == C[i - 1 + j]);
        }
    return dp[x][y];
}

int main(){
    string a = "yx" , b = "x" , c = "xxy";
    cout<<isInterleave(a,b,c)<<endl;

    a = "xy" , b = "x" , c = "xxy";
    cout<<isInterleave(a,b,c);
}
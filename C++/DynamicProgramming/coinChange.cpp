#include<iostream>
using namespace std;
#include<vector>

int maxWays(int array[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 1; i <= n; i++)
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
                dp[i][j] = dp[i - 1][j] + dp[i][j - array[i - 1]];
        }
    }
    return dp[n][sum];
}

//will check later
// int minCoins(int array[],int sum,int n){
//     int table[V+1];
 
//     // Base case (If given value V is 0)
//     table[0] = 0;
 
//     // Initialize all table values as Infinite
//     for (int i=1; i<=V; i++)
//         table[i] = INT_MAX;
 
//     // Compute minimum coins required for all
//     // values from 1 to V
//     for (int i=1; i<=V; i++)
//     {
//         // Go through all coins smaller than i
//         for (int j=0; j<m; j++)
//           if (coins[j] <= i)
//           {
//               int sub_res = table[i-coins[j]];
//               if (sub_res != INT_MAX && sub_res + 1 < table[i])
//                   table[i] = sub_res + 1;
//           }
//     }
   
//       if(table[V]==INT_MAX)
//         return -1;
   
//     return table[V];
// }

int main(){
    int coin[] = {1,2,3};
    int n = 5;
    cout<<maxWays(coin,n,3);
}
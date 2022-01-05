#include <iostream>
using namespace std;
#include <cstring>

int minOf(int a,int b,int c){
    if(a<b){
        if(a<c)
            return a;
        
        else 
            return c;
    }

    else{
        if(b<c)
            return b;
        else 
            return c;
    }
}

int editDistance(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        
        int dp[l1+1][l2+1];
        
        for(int i=0;i<=l1;i++)
            for(int j=0;j<=l2;j++){
                if(i==0)
                    dp[i][j] = j;
                    
                else if(j==0)
                    dp[i][j] = i;
                
                else if(s[i-1]==s[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                else
                    dp[i][j] = 1 + minOf(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        return dp[l1][l2];
    }

int main()
{
    // string s = "sunday";
    // string t = "saturdsay";
    // cout<<editDistance(s,t);
    cout<<minOf(-2,-62,-783);
}
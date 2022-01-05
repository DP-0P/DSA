#include<iostream>
using namespace std;
#include<cstring>

const int SIZE = 1e3;
const int INF = INT_MAX;


int dp[SIZE][SIZE];
class Solution{
public:

    bool checkPal(string s, int left, int right){
        while(left<=right){
            if(s[left] != s[right]){
                return false;
            }
            left+=1;
            right-=1;
        }
        return true;
    }

    int solve(string str, int left, int right){
    
        if(left>=right){
            return 0;
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        if(checkPal(str,left,right)){
            return 0;
        }
        
        int val = INF;
        
        for(int k=left; k<right ;k++){
            if(checkPal(str,left,k)){
                val = min(val, 1+ solve(str, k+1,right));
            }
        }
        
        return dp[left][right]=val;
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int left=0;
        int right = str.size() - 1;
        
        return solve(str, left, right);
    }
};
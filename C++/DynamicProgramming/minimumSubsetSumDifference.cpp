#include <iostream>
#include <vector>
using namespace std;

int minimumSubsetSumDifferencr(vector<int> vect){
    int sum = 0;
    for(int i=0;i<vect.size();i++)
        sum+=vect[i];
    
    bool dp[vect.size()+1][sum+1];

    for(int i=0;i<=vect.size();i++)
        dp[i][0] = true;
    
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;
    
    for(int i=1;i<=vect.size();i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];

            if(vect[i-1]<=j)
                dp[i][j] = dp[i-1][j-vect[i-1]];
        }
    }
    int diff = INT_MAX;

    for(int i=sum/2;i>=0;i--){
        if(dp[vect.size()][i]==true){
            diff = sum-2*i;
            break;
        }
    }
    return diff;
}

int main(){
    vector<int> vect = {1,5,6,15};
    cout<<minimumSubsetSumDifferencr(vect);
}
#include <iostream>
#include <vector>
using namespace std;

bool equalSumPartition(vector<int> vect){
    int sum = 0;
    for(int i=0;i<vect.size();i++)
        sum += vect[i];
    
    if(sum%2 != 0)
        return false;
    
    bool dp[sum/2+1][vect.size()+1];

    for(int i=0;i<=vect.size();i++)
        dp[0][i] = true;
    
    for(int i=1;i<=sum/2;i++)
        dp[i][0] = false;

    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=vect.size();j++){
            dp[i][j] = dp[i][j-1];
            if(i>= vect[j-1])
                dp[i][j] = dp[i][j] or dp[i-vect[j-1]][j-1];
        }
    }
    return dp[sum/2][vect.size()];
}

int main(){
    vector<int> vect = {5,1,5,11};
    cout<<equalSumPartition(vect);
}
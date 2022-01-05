#include <iostream>
using namespace std;

int friendsPairingDP(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

//not working
int dp[1000];
int friendsPairingRecursion(int n){
    if (dp[n] != -1)
        return dp[n];
 
    if (n > 2)
        return dp[n] = friendsPairingRecursion(n - 1) + (n - 1) * friendsPairingRecursion(n - 2);
    else
        return dp[n] = n;
}

int friendsPairingIterative(int n){
    int a=1,b=2,c=0;
    if (n <= 2)
        return n;
    
    for (int i = 3; i <= n; i++) {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n=6569;
    cout<<friendsPairingDP(n)<<endl;
    cout<<friendsPairingRecursion(n)<<endl;
    cout<<friendsPairingIterative(n);
}
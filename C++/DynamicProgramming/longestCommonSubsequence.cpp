#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

int lcsRecursive(string &a,string &b,int al,int bl){
    if(al==0 || bl==0)
        return 0;
    
    if(a[al-1] == b[bl-1])
        return 1 + lcsRecursive(a,b,al,bl);
    
    else
        return max(lcsRecursive(a,b,al,bl-1),lcsRecursive(a,b,al-1,bl));
}

int lcsIterative(string &a,string &b){
    int al = a.size();
    int bl = b.size();
    int lcs[al+1][bl+1];

    for(auto i=0;i<=al;i++)
        for(auto j=0;j<=bl;j++){
            if(i==0 || j==0)
                lcs[i][j] = 0;

            else if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            
            else    
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    return lcs[al][bl];
}

int main(){
    string a = "aggtab";
    string b = "gxtxayb";
    int al = a.size();
    int bl = b.size();
    cout<<lcsRecursive(a,b,al,bl);
    cout<<endl;
    cout<<lcsIterative(a,b);
}
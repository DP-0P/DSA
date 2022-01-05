#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> vec = {1,2,3};
    int n = 4;
    vector<int> table(n+1);
    table[0] = 1;
    for(int i=0;i<vec.size();i++)
        for(int j=vec[i];j<=n;j++)
            table[j] += table[j-vec[i]];
    cout<<table[n];
}
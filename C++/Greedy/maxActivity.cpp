#include<iostream>
#include<vector>
using namespace std;

void maxActivity(vector<int> ar,vector<int> arr){
    int i=0;
    int c=0;
    for(int j=1;j<arr.size();j++)
        if(ar[j]>=arr[i]){
            cout <<" " << j;
            i=j;
            c++;
        }
    cout<<c;
}

int main(){
    vector<int> ar = {1,3,0,5,8,5};
    vector<int> arr = {2,4,6,7,9,9};
    maxActivity(ar,arr);
}
#include<iostream>
using namespace std;

void countSetBits(int n){
    int count = 0;
    while(n){
        count += n&1;
        n>>=1;
    }
    cout<<count<<endl;
}

int main(){
    countSetBits(9);
}
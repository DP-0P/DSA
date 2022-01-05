#include<iostream>
using namespace std;

int n1 = 0,n2 = 1,n3;

void fiboSeries(int n){
    if(n==0)
        return;
    n3 = n1+n2;
    n1 = n2;
    n2 = n3;
    cout<<n3<<" ";
    fiboSeries(n-1);
}

int fibo(int n){
    if(n<=1)
        return n;

    return fibo(n-1)+fibo(n-2);
}

int gf(int n){
    if(n<=1)
        return n;
    
    return gf(n-2)*2 - gf(n-1);
}

int main(){
    // cout<<fibo(9)<<endl;
    // fiboSeries(9);
    cout<<gf(3);
}
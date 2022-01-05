#include<iostream>
using namespace std;

int s = 0;

int reverse(int n){
    int m=n;
    if(n>0){
        s=s*10+n%10;
        reverse(n/10);
    }
    else
        return s;
}

bool palindrome(int n){
    int rev = reverse(n);

    return rev==n;
}

int main(){
    cout<<palindrome(66);
}
#include<iostream>
#include<cstring>
using namespace std;

void isPlaindrome(char S[])
{
    int start = 0 ;
    int end = strlen(S)-1;
    
    while(start<end)
        if(S[start++] != S[end--])
            cout<<"Not Palindrome";
    cout<<"Palindrome";
}

int main(){
    isPlaindrome("abba");
}
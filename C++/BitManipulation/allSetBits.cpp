#include<iostream>
using namespace std;


    
    int countSetBits(int n)
    {
        int count = 0;
        for(int i=1;i<=n;i++)
            count += cou(i);
        
        return count;
    }
    
    int cou(int n){
        int count = 0;
        while(n){
            count += n&1;
            n>>=1;
        }
        return count;
    }
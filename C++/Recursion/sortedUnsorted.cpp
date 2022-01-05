#include<iostream>
using namespace std;

bool sortChk(int array[],int i,int n){
    if(i==n)
        return true;
    
    if(array[i]>array[i-1]) 
        sortChk(array,i+1,n);
    
    else
        return false;
}

int main(){
    int array[] = {1,2,3,4,5};
    cout<<sortChk(array,1,5);
}
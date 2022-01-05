#include<iostream>
using namespace std;

int knapsack(int w,int wt[],int val[],int n){
    if(n==0 || w==0)
        return 0;
    
    if(wt[n-1]>w)
        return knapsack(w,wt,val,n-1);
    
    else
        return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
}

int main(){
    int n = 5;
    int w = 9;
    int values[] = {10,10,40,80,100};
    int weight[] = {1,2,4,5,6};
    cout<<knapsack(w,weight,values,n);
}
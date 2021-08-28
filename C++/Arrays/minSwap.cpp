#include<iostream>
using namespace std;

int minSwap(int array[],int k){
    int want = 0;
    for(int i=0;i<5;i++)
        if(array[i]<=k)
            want++;
    
    int unwant = 0;
    for(int i=0;i<want;i++)
        if(array[i]>k)
            unwant++;
    
    int swap = unwant;
    for(int i=0,j=want;j<5;j++,i++){

        if(array[i]>k)
            unwant--;

        if(array[j]>k)
            unwant++;

        if(swap>unwant)
            swap = unwant;
    }
    return swap;
}

int main(){
    int array[] = {2, 1, 5, 6, 3};
    cout<<minSwap(array,3)<<endl;
}
#include<iostream>
using namespace std;


int main(){

    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    
    int c=-1;
    for(int i=0;i<10;i++){
        if(arr[i]<0){
            c++;
            int temp = arr[i];
            arr[i] = arr[c];
            arr[c] = temp ;
        }
    }

    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
}
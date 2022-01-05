#include<iostream>
using namespace std;

int main(){
    int array[] = {15, 2, 45, 12, 7};
    for(int i=0;i<5;i++)
        if(array[i] == i+1)
            cout<<i+1<<endl;
}
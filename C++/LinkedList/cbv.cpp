#include<iostream>
using namespace std;

void swap(int *a,int *b){
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

int main(){
    int a = 5;
    int b = 4;
    swap(&a,&b);
    cout<<a<<" "<<b;
}
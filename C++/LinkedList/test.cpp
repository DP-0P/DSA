#include<iostream>
using namespace std;

int main(){
    int x = 69;
    // int *a = &x;
    int *a;
    a = &x;
    int **b = &a;
    // cout<<a<<endl;//0x7bfe14
    // cout<<*a<<endl;//69
    // cout<<&a<<endl;//0x7bfe08

    // cout<<**a<<endl;
    printf("%d\n",a);//8125972 address of x
    printf("%d\n",*a);//69 value of x
    printf("%d\n",&a);//8125960 address of a

    printf("%d\n",b);//8125960 address of a
    printf("%d\n",*b);//8125972 value of a = address of x
    printf("%d\n",**b);//69 value of x 

    
}
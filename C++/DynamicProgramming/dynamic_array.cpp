#include<iostream>
using namespace std;

int main(){
    char i='0';
    char *p = &i;
    cout<<sizeof(*p);
}
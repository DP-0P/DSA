#include<iostream>
using namespace std;
int main(){
    string name;
    cout<<"Enter ur name ";
    cin>>name;
    cout<<name;

    int array[] = {1,2,3,4,5};
    int size = *(&array + 1) - array;
    cout<<size;

    // for(int i=0;i<sizeof(array);i++)
    //     cout<<array[i]<<"\n";

    return 0;
}
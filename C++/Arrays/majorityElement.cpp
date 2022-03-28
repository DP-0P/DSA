#include <iostream>
#include <unordered_map>
using namespace std;

int majorityElement(int a[], int size){
    unordered_map<int,int> map;
    for(auto i=0;i<size;i++)
        map[a[i]]++;
    
    for(auto i:map)
        if(i.second>size/2)
            return i.first;
    
    return -1;
}

int main(){
    int arr[] = {3,1,3,3,2};
    cout<<majorityElement(arr,5);
}
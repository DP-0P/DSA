#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double MedianOfArrays(vector<int>& array1, vector<int>& array2){
    vector<int> arr;
    int i=0,j=0;
    while(i<array1.size() and j<array2.size()){
        if(array1[i]<=array2[j]){
            arr.push_back(array1[i]);
            i++;
        }
        else{
            arr.push_back(array2[j]);
            j++;
        }
    }
        
    while(i<array1.size()){
        arr.push_back(array1[i]);
        i++;
    }
        
    while(j<array2.size()){
        arr.push_back(array2[j]);
        j++;
    }
        
    double median = 0;
    if((array1.size()+array2.size())%2!=0)
        median = arr[(array1.size()+array2.size())/(double)2];
        
    else
        median = (arr[(array1.size()+array2.size())/(double)2] + arr[((array1.size()+array2.size())/(double)2)-1])/(double)2;
        
    return median;
}

int main(){
    vector<int> v = {1,5,9};
    vector<int> w = {2,3,6,7};

    cout<<MedianOfArrays(v,w);
}
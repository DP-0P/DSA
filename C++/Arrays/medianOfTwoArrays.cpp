#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        vector<int> array(array1.size()+array2.size());
        // cout<<"workingg";
        
        int i;
        for(i=0;i<array1.size();i++)
            array[i] = array1[i];
        // cout<<i<<endl;
        for(;i<array1.size()+array2.size();i++)
            array[i] = array2[i-array1.size()];

            // cout<<"workingg";
        sort(array.begin(),array.end());
        for(auto i : array)
            cout<<i<<" ";
        
        if(array.size() %2 == 0){
            int middle = array.size()/2;
            double res = (array[middle] + array[middle + 1])/2;
            return res;
        }

        
        
        int middle = array.size()/2;
        // cout<<middle<<"middle element";
        // double res = array[middle+1];
        // cout<<res;
        return double(array[middle]);
    }

int main(){
    vector<int> v = {1,5,9};
    vector<int> w = {2,3,6,7};

    cout<<MedianOfArrays(v,w);
}
#include<iostream>
using namespace std;
#include<vector>

//kadane's algorithm
void maxSubArray(vector<int> &array){
    int max = array[0];
    int current = 0;

    for(int i=0;i<array.size();i++){
        current += array.at(i);

        if(current>max)
            max = current;
        
        if(current<0)
            current = 0;
    }
    cout<<max;
}

int main(){
    vector<int> array = {-10,-2,-3};
    maxSubArray(array);
}
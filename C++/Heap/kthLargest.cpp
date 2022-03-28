#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int> vect,int k){
    int c=0;
    priority_queue <int,vector<int>,greater<int>> maxHeap;
    for(int i=0;i<vect.size();i++){
        maxHeap.push(vect[i]);
        c++;
        if(c>k){
            maxHeap.pop();
            c--;
        }
    }
    return maxHeap.top();
}

int main(){
    vector<int> vect = {7,10,4,3,20,15};
    cout<<kthLargest(vect,3);
}
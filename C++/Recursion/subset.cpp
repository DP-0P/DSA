#include<iostream>
using namespace std;
#include<vector>

void subset(vector<int> input,vector<int> output,int index){
    if(index==input.size()){
        for(int i=0;i<output.size();i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }

    subset(input,output,index+1);

    output.push_back(input[index]);
    subset(input,output,index+1);
}

int main(){
    cout<<"Enter size :";
    int size;
    cin>>size;

    vector<int> input(size);
    for(int i=0;i<size;i++)
        cin>>input[i];
    vector<int> output;

    subset(input,output,0);
}
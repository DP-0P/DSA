#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//not optimized
void merge(vector<int> &vec1,vector<int> &vec2){
    int i=0;

    while(vec1[vec1.size()-1]>vec2[0]){
        if(vec1[i]>vec2[0]){
            swap(vec1[i],vec2[0]);
            sort(vec2.begin(),vec2.end());
        }
        i++;
    }
}
//better
void merge2(vector<int> &vec1,vector<int> &vec2){
    int i=0,j=0,k=vec1.size()-1;

    while(i<=k && j<vec2.size()){
        if(vec1[i]<vec2[j])
            i++;
        else    
            swap(vec2[j++],vec1[k--]);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
}

int main(){
    vector<int> vec1 = {1, 5, 9, 10, 15, 20};
    vector<int> vec2 = { 2, 3, 8, 13 };

    merge2(vec1,vec2);
    for(auto w :vec1)
        cout<<w<<" ";
    cout<<endl;
    for(auto w :vec2)
        cout<<w<<" ";
}
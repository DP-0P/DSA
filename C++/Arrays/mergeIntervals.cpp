#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> merged;

    if(intervals.size()==0)
        return merged;
    
    sort(intervals.begin(),intervals.end());

    vector<int> tempInterval = intervals[0];

    for(auto it : intervals){
        if(it[0]<=tempInterval[1])
            tempInterval[1] = max(it[1],tempInterval[1]);

        else{
            merged.push_back(tempInterval);
            tempInterval = it;
        }
    }
    merged.push_back(tempInterval);
    return merged;
}

int main(){
    vector<vector<int>> intervals = {{1,2},{1,1},{3,5},{3,4},{4,5}};

    // for(auto i=0;i<intervals.size();i++)
    //     for(auto j=0;j<intervals[i].size();j++)
    //         cout<<intervals[i][j]<<" ";
    
    cout<<endl;

    intervals = merge(intervals);

    for(auto i=0;i<intervals.size();i++)
        for(auto j=0;j<intervals[i].size();j++)
            cout<<intervals[i][j]<<" ";
}
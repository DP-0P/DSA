#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> result;

void combinationalSum(vector<int> &arr, int b, vector<int> temp, int sum, int k)
{
    if (sum == b)
    {
        result.push_back(temp);
        return;
    }

    if (sum > b)
        return;

    if (sum < b)
        for (int i = k; i < arr.size(); i++)
        {
            temp.push_back(arr[i]);
            combinationalSum(arr, b, temp, sum + arr[i], i);
            temp.pop_back();
        }
}

int main(){
    vector<int> array = {7,2,6,5};
    sort(array.begin(), array.end());
    array.erase(unique(array.begin(), array.end()), array.end());
    int target = 16;
    combinationalSum(array, target, {}, 0, 0);

    for(auto i = 0;i<result.size();i++){
        for(auto j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
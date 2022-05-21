#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c){
    vector<int> vec;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            vec.push_back(matrix[i][j]);

    sort(vec.begin(), vec.end());
    return vec[(r * c - 1) / 2];
}

int main(){}
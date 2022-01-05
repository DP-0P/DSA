#include <iostream>
using namespace std;
#include <vector>

void spiral(vector<vector<int>> &array)
{

    int top = 0;
    int bottom = array.size()-1;
    cout<<bottom<<endl;
    int left = 0;
    int right =array[0].size()-1;
    cout<<right<<endl;

    while (top<=bottom && left<=right)
    {
        for (int i = left; i <= right; i++)
            cout << array[top][i] + " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << array[i][right] + " ";
        right--;

        for (int i = right; i >= left; i--)
            cout << array[bottom][i] + " ";
        bottom--;

        for (int i = bottom; i >= top; i--)
            cout << array[i][left] + " ";
        left++;
    }
}

void spiral(int array[][3],int r,int c){

}

int main()
{
    // int n = 3;
    int r,c;
    r=3;
    c=3;
    vector<vector<int>> array{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         array[i][j] = 1;
    // }

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout<<endl;

    
    // cout<<array<<endl;
    spiral(array);
}

#include <iostream>
#include <vector>
using namespace std;

// int minJumps(int arr[], int n)
// {
//     int c=0;
//         int sum =0;
//     for(int i=0;i<n;){
//         c++;
//         i+=arr[i];
//         if(i>=n-1)
//         return c;
//     }
//     return -1;
// }

bool canJump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return false;

    if (nums[0] == 0)
        return false;

    int max = nums[0];
    int step = nums[0];
    int jump = 1;
    int i;
    for (i = 1; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            return true;

        if (max < i + nums[i])
            max = i + nums[i];
        step--;

        if (step == 0)
        {
            jump++;
            if (i >= max)
                return false;

            step = max - 1;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    vector<int> nums = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<canJump(nums);
    // cout<<minJumps(arr,6);
}
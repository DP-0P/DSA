#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i <= k; i++)
        minHeap.push(nums[i]);
 
    int index = 0;
    for (int i = k + 1; i < nums.size(); i++)
    {
        nums[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(nums[i]);
    }

    while (!minHeap.empty())
    {
        nums[index++] = minHeap.top();
        minHeap.pop();
    }
}
 
int main()
{
    vector<int> nums = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
    sortKSortedArray(nums, k);
    for (int i: nums) 
        cout << i << " ";

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n,k;
	    vector<int> nums(n,0);
	    for(int i=0;i<n;i++)
	        cin>>nums[i];            
	    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i <= k; i++)
        minHeap.push(nums[i]);
 
    int index = 0;
    for (int i = k + 1; i < nums.size(); i++)
    {
        nums[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(nums[i]);
    }

    while (!minHeap.empty())
    {
        nums[index++] = minHeap.top();
        minHeap.pop();
    }
	    for (int i: nums) 
            cout << i << " ";
	}
	return 0;
}


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     priority_queue<int,vector<int>,greater<int>>pq;
     for(int i=0;i<k;i++)
    {
      pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
     cout<<pq.top()<<" ";
     pq.pop();
     pq.push(arr[i]);
    }
      while(!pq.empty())
     {
      cout<<pq.top()<<" ";
      pq.pop();
     }
      cout<<endl;
    
   }
return 0;
}
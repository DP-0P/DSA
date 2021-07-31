#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        for(int i=0;i<nums.size();i++){
            if(nums.at(mid)==0){
                int temp = nums.at(mid);
                nums.at(mid) = nums.at(low);
                nums.at(low) = temp;
                low++;
                mid++;
            }
            
            else if(nums.at(mid)==1)
                mid++;
            
            else{
                int temp = nums.at(mid);
                nums.at(mid) = nums.at(high);
                nums.at(high) = temp;
                high--;
            }
        }
        for(int i=0;i<nums.size();i++)
            cout<<nums.at(i)<<endl;
    }

    void sort012Noob(vector<int>& nums) {
        int c0;
        int c1=0;
        int c2;
        for(int i=0;i<nums.size();i++){
            
            if(nums.at(i)==0)
                c0++;
            
            if(nums.at(i)==1)
                c1++;
            
            if(nums.at(i)==2)
                c2++;
        }
        
        int i=0;
        
        while(c0>0){
            nums.at(i)=0;
            i++;
            c0--;
        }
        
        while(c1>0){
            nums.at(i)=1;
            i++;
            c1--;
        }
        
        while(c2>0){
            nums.at(i)=2;
            i++;
            c2--;
        }
        for(int i=0;i<nums.size();i++)
            cout<<nums.at(i)<<endl;
    }
    
int main()
{
    vector<int> nums = {0,2,1,2,2,1,0,1,0};
    // sort012(nums);
    sort012Noob(nums);
}

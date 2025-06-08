//using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++)
            temp = temp^nums[i];
        return temp;
    }
};

//using map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums)
            mp[i]++;
        
        for(auto it : mp)
            if(it.second == 1)
                return it.first;
        
        return -1;
    }
};

/*
Leetcode Question 136. Single Number
https://leetcode.com/problems/single-number/
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        
        //Solution 1
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second == 1)
                return i->first;
        }
        return 0;
        

        //Solution 2
        int xorsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorsum = xorsum ^ nums[i];
        }
        return xorsum;
    }
};
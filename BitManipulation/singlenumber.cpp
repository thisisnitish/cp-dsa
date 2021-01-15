/*
Leetcode Question 136. Single Number
https://leetcode.com/problems/single-number/
*/

//Solution 1
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        
        
        //O(n)
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second == 1)
                return i->first;
        }
        return 0;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(n)
    int singleNumber(vector<int> &nums)
    {
        int xorsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorsum = xorsum ^ nums[i];
        }
        return xorsum;
    }
};
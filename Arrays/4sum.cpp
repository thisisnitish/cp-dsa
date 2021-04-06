/*
Leetcode Question 18. 4Sum
https://leetcode.com/problems/4sum/
*/

class Solution
{
public:
    /*the basic idea is to use 2 pointer approach, if you have done 
    the 3Sum problem then this problem is easy for you. we have used 
    the same technique for this problem. So better do the 3Sum before 
    doing this problem. Time: O(N^3), Space: O(N)*/
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            //to handle the duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < len; j++)
            {
                //to handle the duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = len - 1;

                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        //to handling the duplicates
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }
};

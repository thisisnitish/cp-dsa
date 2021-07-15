/*
Leetcode Question 611. Valid Triangle Number
https://leetcode.com/problems/valid-triangle-number/
*/

//Brute Force
class Solution
{
public:
    //Time: O(n^3), Space: O(1)
    int triangleNumber(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if ((nums[i] + nums[j] > nums[k]) && (nums[i] + nums[k] > nums[j]) && (nums[j] + nums[k] > nums[i]))
                        count++;
                }
            }
        }
        return count;
    }
};

//Efficient Approach
class Solution
{
public:
    //Time: O(n^2)
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            int low = 0, high = i - 1;

            while (low < high)
            {
                if (nums[low] + nums[high] > nums[i])
                {
                    count += high - low;
                    high--;
                }
                else
                    low++;
            }
        }
        return count;
    }
};

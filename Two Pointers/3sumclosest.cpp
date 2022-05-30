/*
Leetcode Question 16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/
*/

class Solution
{
public:
    //Time: O(nlogn + n^2), Space: O(1)
    int threeSumClosest(vector<int> &nums, int target)
    {
        int mindiff = INT_MAX;
        int result = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            int x = nums[i];

            while (left < right)
            {
                int sum = x + nums[left] + nums[right];

                if (abs(target - sum) < abs(mindiff))
                {
                    mindiff = abs(target - sum);
                    result = sum;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
                if (target == sum)
                    return result;
            }
        }
        return result;
    }
};

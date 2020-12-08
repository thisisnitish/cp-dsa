/*
Leetcode Question 15. 3Sum
https://leetcode.com/problems/3sum/
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> threesum;
        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (unsigned int i = 0; i < len; i++){

            //to handle the duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = len - 1;
            int x = nums[i];

            while (left < right){
                if ((x + nums[left] + nums[right]) == 0){
                    threesum.push_back(vector<int>{x, nums[left], nums[right]});

                    //to handle the duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    //to handle the duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if ((x + nums[left] + nums[right]) < 0)
                    left++;
                else
                    right--;
            }
        }
        return threesum;
    }
};

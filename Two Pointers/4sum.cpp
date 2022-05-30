/*
Leetcode Question 18. 4Sum
https://leetcode.com/problems/4sum/
*/

/*
One thing I would say, if you are directly here without knowing about 2Sum and 3Sum problem.
Then, it is my humble request to you, please go and attempt those questions. First do 2Sum
then 3sum then come to this problem.

This question is very similar to the 3Sum problem. First thing we can do it to sort the array
so that it will be easy for us to compare two elements, also the duplicates will be together
so because of sorting we can handle duplicates as well.

We have to go down more. Just for 4Sum, we need to fix a single element after that
we need 3 elements more to make quadruple. So for 3 elements we can treat as 3Sum problem.

In that again fix the single element and rest other two we can use 2 pointer approach to find
the other two elements.

Now, we can see that from 4Sum we have reduced the problem to 4Sum => 3Sum => 2Pointer 
Approach.

Another observation we can see that, when we sort the array, the same element will come
together, so it will be easy for us to handle duplicates.

Also, if we calculate the sum after that if the sum == target, just push the array to
resultant array and if sum < target we have to increase the left and if sum > target we have
to decrease the right, it's because of the sorted array
*/
class Solution
{
public:
    //Time: O(N^3), Space: O(1)(ignoring 2d vector)
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {

            //to handle the duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < len; j++)
            {

                //to handle the duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = len - 1;

                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        //to handling the duplicates for left and right
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

/*
Leetcode Question 167. Two Sum II - Input Array Is Sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

/*
This question is very similar to the 2 sum problem but here the array is sorted and
it asks to give the indexes of both the elements such that:
1 <= index1 < index2 <= numbers.length

Now, we want something like this, then we can't use BruteForce because it will give TLE.
Also, we cannot use hashmap because, in this way, we are not sure whether we will
get the indexes in the way we want or not.

So, using Two Pointers would be a better idea becuase it will preserver the array and
it's indexes and gives the output in constant extra space.

I was able to solve in 10 mins. 49 sec.
*/

class Solution
{
public:
    // Time: O(N), Space: O(1)
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {};
    }
};

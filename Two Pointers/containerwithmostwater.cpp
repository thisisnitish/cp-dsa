/*
Leetcode Question 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/
*/

// I was able to solve in 27 mins.
// Brute Force
class Solution
{
public:
    // Time: O(N^2), Space: O(1)
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int area = min(height[i], height[j]) * abs(j - i);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

// Two Pointers
/*
Since, we want the maximum area. So, we will start from maximum width. In case of
shifting pointers (height), we will shift only from the smaller side by 1 (Side
which have smaller height)
*/
class Solution
{
public:
    // Time: O(N), Space: O(1)
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right)
        {
            int area = min(height[left], height[right]) * abs(right - left);
            max_area = max(max_area, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

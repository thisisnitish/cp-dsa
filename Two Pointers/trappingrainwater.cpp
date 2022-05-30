/*
Leetcode Question 42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/

//  Leetcode Solution is really nice. Please refer, if you have any problem

// Solution 1
class Solution
{
public:
    // Time: O(N^2), Space: O(N)
    int trap(vector<int> &height)
    {
        int n = height.size();
        int trappedWater = 0;

        for (int i = 0; i < n; i++)
        {
            int maxLeft = 0, maxRight = 0;

            // moving to the left side
            for (int j = i; j >= 0; j--)
            {
                maxLeft = max(maxLeft, height[j]);
            }
            // moving to the right side
            for (int j = i; j < n; j++)
            {
                maxRight = max(maxRight, height[j]);
            }

            int currentTrapped = min(maxLeft, maxRight) - height[i];
            trappedWater += currentTrapped;
        }
        return trappedWater;
    }
};

// Solution 2
class Solution
{
public:
    // Time: O(N), Space: O(N)
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // calculate the left side
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // calculate the right side
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // water cannot be stored at boundaries
        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            trappedWater += min(rightMax[i], leftMax[i]) - height[i];
        }
        return trappedWater;
    }
};

// Two Pointers
class Solution
{
public:
    // Time: O(N), Space: O(1)
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        int trappedWater = 0, left = 0, right = n - 1;
        int leftMax = height[left], rightMax = height[right];

        while (left < right)
        {
            if (leftMax < rightMax)
            {
                left++;
                leftMax = max(leftMax, height[left]);
                trappedWater += leftMax - height[left];
            }
            else
            {
                right--;
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
            }
        }
        return trappedWater;
    }
};

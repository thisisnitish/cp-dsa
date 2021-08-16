/*
Leetcode Question 1351. Count Negative Numbers in a Sorted Matrix
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

//Brute Force
class Solution
{
public:
    //Time: O(mn)
    int countNegatives(vector<vector<int> > &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> v = grid[i];
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] < 0)
                    count++;
            }
        }
        return count;
    }
};

//Binary Search
class Solution
{
public:
    //Time: O(mlogn), Space: O(1)
    int countNegatives(vector<vector<int> > &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            count += helper(grid[i]);
        }
        return count;
    }

    int helper(vector<int> &v)
    {
        int low = 0, high = v.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (v[mid] >= 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return v.size() - 1 - high;
    }
};

//Binary Search Prunning
class Solution
{
public:
    //Time: O(m+n), Space: O(1)
    int countNegatives(vector<vector<int> > &grid)
    {
        int m = grid.size();    //rows
        int n = grid[0].size(); //cols

        int i = m - 1, j = 0;
        int count = 0;
        while (i >= 0 && j < n)
        {
            if (grid[i][j] < 0)
            {
                count += (n - j);
                i--;
                j = 0;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};
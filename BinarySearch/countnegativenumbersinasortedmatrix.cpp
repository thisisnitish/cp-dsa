/*
Leetcode Question 1351. Count Negative Numbers in a Sorted Matrix
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

//Brute Force
class Solution
{
public:
    //Time: O(mn), Space: O(1)
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

//Using Binary Search
class Solution
{
public:
    //Time: O(m+n), Space: O(1)
    int countNegatives(vector<vector<int> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int i = m - 1, j = 0;
        int count = 0;
        // to start from the grid[m-1][0] position
        while (i >= 0 && j < n)
        {
            if (grid[i][j] < 0)
            {
                //when the first occurrence of a number in a row is -ve, all following
                //numbers will be -ve. So, add their count.
                count += (n - j);
                i--; //then move to the above row
            }
            else
                j++; //else move to the right (i.e. to the next column)
        }
        return count;
    }
};

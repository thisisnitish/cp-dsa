/*
Leetcode Question 240. Search a 2D Matrix II
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

//Solution 1
class Solution
{
public:
    /*the basic idea is to traverse the entire matrix
    if you find just return true else false
    Time: O(N), Space: O(1)*/
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;

        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;

        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
            {
                if (target == matrix[r1][c])
                    return true;
            }

            for (int r = r1 + 1; r <= r2; r++)
            {
                if (target == matrix[r][c2])
                    return true;
            }

            if (r1 < r2 && c1 < c2)
            {
                for (int c = c2 - 1; c > c1; c--)
                {
                    if (target == matrix[r2][c])
                        return true;
                }
                for (int r = r2; r > r1; r--)
                {
                    if (target == matrix[r][c1])
                        return true;
                }
            }

            r1++;
            r2--;
            c1++;
            c2--;
        }
        return false;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is to traverse the entire matrix
    from the top right corner and start comparing the 
    elements with target Time: O(N), Space: O(1)*/
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;

        int r = 0, c = matrix[0].size() - 1;
        while (r < matrix.size() && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};

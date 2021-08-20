/*
Leetcode Question 74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/
*/

//Solution 1
class Solution
{
public:
    /*
    Time: O(m + n), Space: O(1)
    Basic idea is to apply binary search from the top right corner of the matrix and start
    comparing the elements.
    */
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (matrix.empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            //if target is found then return true
            if (matrix[i][j] == target)
                return true;
            /*if target is less than the element then entire column is useless so go to the 
            next column*/
            else if (matrix[i][j] > target)
                j--;
            /*if target is more than the element then entire row is useless so go to the
            next row*/
            else if (matrix[i][j] < target)
                i++;
        }
        //if didn't found the element
        return false;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is to traverse the entire matrix.
    if found return true else false
    Time: O(N), Space: O(1)*/
    bool searchMatrix(vector<vector<int> > &matrix, int target)
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

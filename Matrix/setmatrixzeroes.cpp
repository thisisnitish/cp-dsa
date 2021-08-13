/*
Leetcode Question 73. Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution
{
public:
    //Time: O(m*n), Space: O(m+n)
    void setZeroes(vector<vector<int> > &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> rows;
        vector<int> cols;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (find(rows.begin(), rows.end(), i) != rows.end() ||
                    find(cols.begin(), cols.end(), j) != cols.end())
                    matrix[i][j] = 0;
            }
        }
    }
};

/*
Leetcode Question 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/
*/

class Solution
{
public:
    /*the basic is to simply traverse the matrix
    Time: O(N), Space: O(N)*/
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> resultantArray;

        if (matrix.empty())
            return vector<int>();

        int r1, c1, r2, c2;
        r1 = 0;
        r2 = matrix.size() - 1;
        c1 = 0;
        c2 = matrix[0].size() - 1;

        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
                resultantArray.push_back(matrix[r1][c]);

            for (int r = r1 + 1; r <= r2; r++)
                resultantArray.push_back(matrix[r][c2]);

            if (c1 < c2 && r1 < r2)
            {
                for (int c = c2 - 1; c > c1; c--)
                    resultantArray.push_back(matrix[r2][c]);
                for (int r = r2; r > r1; r--)
                    resultantArray.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }

        return resultantArray;
    }
};

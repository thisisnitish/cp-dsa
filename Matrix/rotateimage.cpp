/*
Leetcode Question 48. Rotate Image
https://leetcode.com/problems/rotate-image/
*/

class Solution
{
public:
    /*the basic idea is to take transpose of
    a matrix and reverse the rows. Time: O(N^2), Space: O(1)*/
    void rotate(vector<vector<int> > &matrix)
    {
        if (matrix.empty())
            return;

        //take the transpose
        int size = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix.size(); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //reverse the rows
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size() / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - j - 1];
                matrix[i][matrix.size() - j - 1] = temp;
            }
        }
    }
};
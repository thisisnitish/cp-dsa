/*
Leetcode Question 51. N-Queens
https://leetcode.com/problems/n-queens/
*/

class Solution
{
public:
    //Time: O(N^2)
    vector<vector<string> > result;
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row, dupcol = col;

        //check for the upper row
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        //check for the left side
        row = duprow;
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        //check for the left down side
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        //if everything is fine
        return true;
    }

    void helper(int col, vector<string> &board, int n)
    {
        if (col == n)
        {
            result.push_back(board);
            return;
        }
        //for every col just try every row means for every col check every value means
        //go vertically down
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                helper(col + 1, board, n);    //for the next column
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        helper(0, board, n);
        return result;
    }
};

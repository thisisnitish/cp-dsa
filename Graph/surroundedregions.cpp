/*
Leetcode Question 130. Surrounded Regions
https://leetcode.com/problems/surrounded-regions/
*/

/*
1. First convert the O's at borders to some letter say 'P'
2. Now, traverse the matrix and convert the rest 'O' to 'X' and 'P' to 'O'
*/
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    void solve(vector<vector<char> > &board)
    {
        int m = board.size();
        int n = board[0].size();

        //for rows, columns are fixed
        for (int i = 0; i < m; i++)
        {
            helper(board, i, 0, m, n);
            helper(board, i, n - 1, m, n);
        }

        //for columns, rows are fixed
        for (int j = 0; j < n; j++)
        {
            helper(board, 0, j, m, n);
            helper(board, m - 1, j, m, n);
        }

        //now traverse the matrix and convert P to O and O to X
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }

    void helper(vector<vector<char> > &board, int x, int y, int m, int n)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;

        board[x][y] = 'P';
        helper(board, x + 1, y, m, n);
        helper(board, x - 1, y, m, n);
        helper(board, x, y + 1, m, n);
        helper(board, x, y - 1, m, n);
    }
};

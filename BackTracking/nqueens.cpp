/*
Leetcode Question 51. N-Queens
https://leetcode.com/problems/n-queens/
*/

class Solution
{
public:
    vector<vector<string>> result;
    vector<string> s;

    void print(vector<vector<int>> v)
    {
        s.clear();
        for (int i = 0; i < v.size(); i++)
        {
            string x = "";

            for (int j = 0; j < v.size(); j++)
            {
                if (v[i][j] == 1)
                {
                    x += "Q";
                }
                else
                {
                    x += ".";
                }
            }
            s.push_back(x);
        }
        result.push_back(s);
    }

    bool isSafe(vector<vector<int>> board, int x, int y)
    {
        /*here we are checking that a particular 
        column consist of a queen or not
        so, for that column we are checking every 
        row we can do the vice versa also i.e. 
        for a row every column*/
        for (int row = 0; row < x; row++)
        {
            if (board[row][y])
                return false;
        }

        //now checking for the diagnols
        //checking for the left diagnol
        int row = x;
        int col = y;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col])
                return false;
            row--;
            col--;
        }

        //checking for the right diagnol
        row = x;
        col = y;

        while (row >= 0 && col < board.size())
        {
            if (board[row][col])
                return false;
            row--;
            col++;
        }

        return true;
    }

    /*we don't the column i.e. y here because as 
    soon as we put the queen in the particular 
    position in a row then we don't need to 
    move further, we can switch to the next row*/
    bool nQueen(vector<vector<int>> &board, int x)
    {
        /*base condition where we have put the 
        n queens to thier respective position*/
        if (x >= board.size())
        { 
            /*this is specific to the questions which is asked, 
            but for generic case we have to change the print function a bit*/
            print(board);     
            return true;
        }

        /*now we will call the function recursively but 
        before we will check for a position whether 
        it is safe or not*/

        for (int col = 0; col < board.size(); col++)
        {
            if (isSafe(board, x, col))
            {
                board[x][col] = 1;

                /*//checking for the next row i.e.
                recursively call to place rest of queens
                if(nQueen(board, x+1)){
                    return true;
                }
                */

                /*for this question specifically we 
                have to do this but above commented 
                if condition, is the generic apporach*/
                nQueen(board, x + 1);

                //backtracking
                board[x][col] = 0;
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> v(n, vector<int>(n, 0));
        nQueen(v, 0);
        return result;
    }
};
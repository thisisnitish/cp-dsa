/*
Leetcode Question 79. Word Search
https://leetcode.com/problems/word-search/
*/

class Solution
{
public:
    bool findWord(vector<vector<char> > &board, string word, int idx, int i, int j)
    {
        // base case or bound check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.' || board[i][j] != word[idx])
            return false;

        if (idx == word.size() - 1)
            return true;
        char temp = board[i][j];
        board[i][j] = '.';

        bool found = findWord(board, word, idx + 1, i + 1, j) ||
                     findWord(board, word, idx + 1, i - 1, j) ||
                     findWord(board, word, idx + 1, i, j + 1) ||
                     findWord(board, word, idx + 1, i, j - 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char> > &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if(board[i][j] == word[0])
                if (findWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

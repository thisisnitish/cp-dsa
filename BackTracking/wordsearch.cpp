/*
Leetcode Question 79. Word Search
https://leetcode.com/problems/word-search/
*/

//Solution 1
class Solution
{
public:
    /*the basic idea is that we have four direction from each cell, and we are using
    dfs here but it will only triggered when we find the first word of the string,
    moreover we can't visited a cell twice. Time: O(N), Space: O(N)*/
    bool exist(vector<vector<char> > &board, string word)
    {
        int r = board.size(), c = board[0].size();

        vector<vector<bool> > visited(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0] && search(board, i, j, word, 0, visited))
                    return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char> > &board, int i, int j, string word, int idx, vector<vector<bool> > &visited)
    {
        if (idx == word.length() - 1)
            return true;
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[idx + 1] && search(board, i - 1, j, word, idx + 1, visited))
            return true;
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[idx + 1] && search(board, i, j - 1, word, idx + 1, visited))
            return true;
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[idx + 1] && search(board, i + 1, j, word, idx + 1, visited))
            return true;
        if (j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[idx + 1] && search(board, i, j + 1, word, idx + 1, visited))
            return true;

        //to mark the cell unvisited
        visited[i][j] = false;
        return false;
    }
};

//Solution 2
class Solution
{
public:
    /*Time: O(N), Space: O(1)*/
    bool exist(vector<vector<char> > &board, string word)
    {
        int r = board.size(), c = board[0].size();
        //go through each character
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                //when you find the first character then run the dfs to find the other
                //word
                if (board[i][j] == word[0] && search(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char> > &board, int i, int j, string word, int idx)
    {
        //make sure that we are not going out of bounds while searching for words
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
        {
            return false;
        };

        //when we reach the end of the word
        if (idx == word.length() - 1)
            return true;

        bool found = false;

        //keep to restore the board the after performing operations
        char temp = board[i][j];

        //marking the cell as visited
        board[i][j] = ' ';

        //Traverse up/down/left/right
        found = search(board, i, j + 1, word, idx + 1) ||
                search(board, i, j - 1, word, idx + 1) ||
                search(board, i - 1, j, word, idx + 1) ||
                search(board, i + 1, j, word, idx + 1);

        board[i][j] = temp;
        return found;
    }
};

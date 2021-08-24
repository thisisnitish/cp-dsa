/*
Leetcode Question 36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/
*/

//Solution 1
class Solution
{
public:
    //Time: O(m*n + m*n + m*n*(i+3)*(j+3)), Space: O(m)
    bool isValidSudoku(vector<vector<char> > &board)
    {
        unordered_map<char, int> mp;

        //check the validity for boxes
        for (auto row : board)
        {
            unordered_map<char, int> mp;
            for (auto r : row)
            {
                if (r != '.')
                {
                    mp[r]++;
                }
                if (mp[r] > 1)
                    return false;
            }
        }

        //check the validity for cols
        for (int j = 0; j < board[0].size(); j++)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < board.size(); i++)
            {
                if (board[i][j] != '.')
                {
                    mp[board[i][j]]++;
                }
                if (mp[board[i][j]] > 1)
                    return false;
            }
        }

        //check for the validity of the boxes
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board.size(); j += 3)
            {
                unordered_map<char, int> mp;
                for (int r = i; r < i + 3; r++)
                {
                    for (int c = j; c < j + 3; c++)
                    {
                        if (board[r][c] != '.')
                        {
                            mp[board[r][c]]++;
                        }
                        if (mp[board[r][c]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

/*
The problem is to come up with an equation to map (n*n) coordinates to (n) numbers so we can 
use it as an index into the blocks array.

Our board would look like this:

(0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7) (0,8)
(1,0) (1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7) (1,8)
(2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8)
(3,0) (3,1) (3,2) (3,3) (3,4) (3,5) (3,6) (3,7) (3,8)
(4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8)
(5,0) (5,1) (5,2) (5,3) (5,4) (5,5) (5,6) (5,7) (5,8)
(6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7) (6,8)
(7,0) (7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7) (7,8)
(8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (8,7) (8,8)

Let's divide this into 3x3 boxes, and label the boxes like this:

0 1 2
3 4 5
6 7 8

Thus
(0,0) (0,1) (0, 2)
(1,0) (1,1) (1, 2)
(2,0) (2,1) (2, 2)
will map to box 0.

And
(0,3) (0,4) (0,5)
(1,3) (1,4) (1,5)
(2,3) (2,4) (2,5)
will map to box 1.

And so on.

We can see that for any coordinate (r, c), the column index (c), which ranges from 0-8 
should contribute either (0, 1, or 2) to the boxIndex. So we can write this as c/3.
This is because of integer division:

{0, 1, 2} / 3 = 0
{3, 4, 5} / 3 = 1
{6, 7, 8} / 3 = 2

Also, for any coordinate (r, c), if the column already contributes (0, 1, or 2) to the 
boxIndex (which has a maximum of 8), then the row index (r) needs to contribute either (0, 
3, or 6) to the boxIndex, since this gives all possible numbers from 0 - 8.
e.g.

0 + {0, 1, 2} = {0, 1, 2}
3 + {0, 1, 2} = {3, 4, 5}
6 + {0, 1, 2} = {6, 7, 8}

Well how do we map {0,1,2,3,4,5,6,7,8} to {0,3,6} ?
We can use integer division again, but multiply the result by 3

({0, 1, 2} / 3) * 3 = (0) * 3 = 0
({3, 4, 5} / 3) * 3 = (1) * 3 = 3
({6, 7, 8} / 3) * 3 = (2) * 3 = 6

So we have boxIndex = c/3 + r/3*3
*/

//Solution 2
class Solution
{
public:
    //Time: O(m*n)
    bool isValidSudoku(vector<vector<char> > &board)
    {
        vector<set<int> > rows(9);
        vector<set<int> > cols(9);
        vector<set<int> > boxes(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int ele = board[i][j] - '0';
                if (rows[i].count(ele) || cols[j].count(ele) || boxes[(i / 3) * 3 + j / 3].count(ele))
                    return false;

                rows[i].insert(ele);
                cols[j].insert(ele);
                boxes[(i / 3) * 3 + j / 3].insert(ele);
            }
        }
        return true;
    }
};

/*
Rat in a Maze Problem - I 
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

class Solution
{
public:
    /*the basic idea is we have done simple traversals in all the 4 directions*/
    void helper(vector<vector<int> > &m, int x, int y, int n, vector<string> &result, string path)
    {
        //doing the bound check
        if (x < 0 || x >= n || y < 0 || y >= n || m[x][y] != 1)
            return;

        /*once you reach the end and completed the path
        push to the result and return*/
        if (x == n - 1 && y == n - 1)
        {
            result.push_back(path);
            return;
        }

        m[x][y] = -1; //mark it visited for the current traversal

        /*moving to all the four directions and checking the every 
        possible path*/
        helper(m, x + 1, y, n, result, path + 'D');
        helper(m, x - 1, y, n, result, path + 'U');
        helper(m, x, y + 1, n, result, path + 'R');
        helper(m, x, y - 1, n, result, path + 'L');

        m[x][y] = 1; //mark it unvisited for further traversals
    }

    vector<string> findPath(vector<vector<int> > &m, int n)
    {
        // Your code goes here
        vector<string> result;
        helper(m, 0, 0, n, result, "");
        sort(result.begin(), result.end());
        return result;
    }
};

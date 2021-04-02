/*
Leetcode Question 733. Flood Fill
https://leetcode.com/problems/flood-fill/
*/

//Solution 1
class Solution
{
public:
    /*the basic idea is reach at that point witht the help of (sr, sc) then 
    check whether the newcolor is equal or not of equal then return image if
    not then do the dfs. Change the color of the cell from newColor when cell
    (sr, sc) is equal to color and do this is all four direcion. Time: O(N),
    Space: O(1)*/
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        int color = image[sr][sc];
        if (color != newColor)
            helper(image, sr, sc, color, newColor);
        return image;
    }

    void helper(vector<vector<int> > &image, int sr, int sc, int color, int newColor)
    {
        if (image[sr][sc] == color)
        {
            image[sr][sc] = newColor;

            if (sr > 0)
                helper(image, sr - 1, sc, color, newColor);
            if (sc > 0)
                helper(image, sr, sc - 1, color, newColor);
            if (sr < image.size() - 1)
                helper(image, sr + 1, sc, color, newColor);
            if (sc < image[0].size() - 1)
                helper(image, sr, sc + 1, color, newColor);
        }
    }
};

//Solution 2
class Solution
{
public:
    /*this is same as the above one with little bit changes. Time: O(1), Space: O(1)*/
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        int color = image[sr][sc];
        if (color != newColor)
            helper(image, sr, sc, color, newColor);
        return image;
    }

    void helper(vector<vector<int> > &image, int sr, int sc, int color, int newColor)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] != color)
            return;
        image[sr][sc] = newColor;

        helper(image, sr - 1, sc, color, newColor);
        helper(image, sr + 1, sc, color, newColor);
        helper(image, sr, sc - 1, color, newColor);
        helper(image, sr, sc + 1, color, newColor);
    }
};

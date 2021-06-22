/*
Leetcode Question 1886. Determine Whether Matrix Can Be Obtained By Rotation
https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
*/

/*
The main idea is to rotate matrix, check everytime that if it equal to the target matrix.
We only have to rotate till 270 deg because after that the matrix will be same
*/
class Solution
{
public:
    //Time: O(N^2), Space: O(1)
    bool findRotation(vector<vector<int> > &mat, vector<vector<int> > &target)
    {
        if (mat == target)
            return true;

        //90 deg
        rotate(mat);
        if (mat == target)
            return true;

        //180 deg
        rotate(mat);
        if (mat == target)
            return true;

        //270 deg
        rotate(mat);
        if (mat == target)
            return true;

        return false;
    }

    void rotate(vector<vector<int> > &mat)
    {

        //transpose of matrix
        for (int i = 0; i < mat.size(); i++)
            for (int j = i; j < mat.size(); j++)
                swap(mat[i][j], mat[j][i]);

        //reverse the rows
        for (int i = 0; i < mat.size(); i++)
            reverse(mat[i].begin(), mat[i].end());
    }
};

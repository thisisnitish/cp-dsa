/*
Leetcode Question 566. Reshape the Matrix
https://leetcode.com/problems/reshape-the-matrix/
*/

/*
Solution 1
1. The simple and brute force way is to put all the matrix elements into the 1D array.
2. Create a 2D aray of size rXc and initialize with 0 & push all the elements of 1D array
into the new matrix
And, by the way the base condition is something very intuitive. Just think about for a sec.
if m*n != r*c then it is clear that new matrix can't accommodate all elements, so just
return the same matrix otherwise calculate the calculate the new one
*/
class Solution
{
public:
    //Time: O(mxn + rxc), Space: O(sizeof(oneDArray) + rxc)
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();

        //base condition
        if (m * n != r * c)
            return mat;

        //convert the matrix to 1d array
        vector<int> oneDArray;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                oneDArray.push_back(mat[i][j]);
            }
        }

        //put all the elements from 1d array to new matrix
        vector<vector<int> > newMatrix(r, vector<int>(c, 0));
        int idx = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                newMatrix[i][j] = oneDArray[idx];
                idx++;
            }
        }
        return newMatrix;
    }
};

/*
Solution 2
Another method is like one pass of the current matrix, and create new matrix initialize with 
0, put the previous elements into the new matrix according to the rxc dimension.
Remember the base condition from the previous solution, we need to apply here also.
*/
class Solution
{
public:
    //Time: O(rxc), Space: O(rxc)
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();

        //base condition
        if (m * n != r * c)
            return mat;

        //creating the new matrix with rxc dimension
        vector<vector<int> > newMatrix(r, vector<int>(c, 0));

        //put all the elements to the new matrix
        int newRow = 0, newColumn = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                //if newColumn is equal to the c then increase the newRow by 1 and set
                //newColumn to 0
                if (newColumn == c)
                {
                    newRow++;
                    newColumn = 0;
                }
                newMatrix[newRow][newColumn] = mat[i][j];
                newColumn++;
            }
        }
        return newMatrix;
    }
};

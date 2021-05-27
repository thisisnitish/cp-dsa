/*
Maximum sum Rectangle 
https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#
*/

class Solution
{
public:
    //Time: O(N*3)
    int kadane(vector<int> &kade, int R)
    {
        int max_sum = INT_MIN, sum = 0;
        for (int i = 0; i < R; i++)
        {
            sum += kade[i];
            max_sum = max(max_sum, sum);

            if (sum < 0)
                sum = 0;
        }
        return max_sum;
    }

    int maximumSumRectangle(int R, int C, vector<vector<int> > M)
    {
        int result = INT_MIN;
        for (int i = 0; i < C; i++)
        {
            vector<int> kade(R, 0);
            for (int x = i; x < C; x++)
            {
                for (int j = 0; j < R; j++)
                {
                    kade[j] += M[j][x];
                }
                int val = kadane(kade, R);
                result = max(result, val);
            }
        }
        return result;
    }
};
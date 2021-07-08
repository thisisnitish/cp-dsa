/*
Leetcode Question 718. Maximum Length of Repeated Subarray
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

/*
If you are fully aware of Longest Common Substring then this question is a piece of cake for 
you. But in case if you didn't, Please go and read about that. Now, coming back to the 
question. The question is return the maximum length of a subarray that appears in both arrays 
or if i would change the statement slightly return the maximum length of a substring that 
appears in both strings. Now, If you have done Longest Common Substring then you will be 
knowing what I'm talking about. Technically, we have to find the Longest Common Subarray.
*/

//Recursive
class Solution
{
public:
    //Time: O(2^(n+m)), Space: O(n)
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        return helper(nums1, nums2, m, n, 0);
    }

    int helper(vector<int> &nums1, vector<int> &nums2, int m, int n, int result)
    {
        if (m == 0 || n == 0)
            return result;

        if (nums1[m - 1] == nums2[n - 1])
            return result = helper(nums1, nums2, m - 1, n - 1, result + 1);
        return max({result, helper(nums1, nums2, m, n - 1, 0), helper(nums1, nums2, m - 1, n, 0)});
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n), without including the recursion stack
    int result = 0;
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        helper(nums1, nums2, m, n, memo);
        return result;
    }

    int helper(vector<int> &nums1, vector<int> &nums2, int m, int n, vector<vector<int> > &memo)
    {
        if (m == 0 || n == 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        helper(nums1, nums2, m, n - 1, memo);
        helper(nums1, nums2, m - 1, n, memo);

        if (nums1[m - 1] == nums2[n - 1])
        {
            memo[m][n] = 1 + helper(nums1, nums2, m - 1, n - 1, memo);
            result = max(result, memo[m][n]);
            return memo[m][n];
        }
        return memo[m][n] = 0;
    }
};

class Solution
{
public:
    //Time: O(m*n), Space: O(m*n), without including the recursion stack
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //Initialization
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return result;
    }
};

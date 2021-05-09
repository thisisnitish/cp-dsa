/*
Leetcode Question 1092. Shortest Common Supersequence
https://leetcode.com/problems/shortest-common-supersequence/
*/

class Solution
{
public:
    /*the basic idea is that this problem can be reduced into lcs, and after
    getting the table we only need to find the scss
    Time: O(n*m), Space: (n*m)*/
    string shortestCommonSupersequence(string str1, string str2)
    {
        return lcs(str1, str2);
    }

    string lcs(string &str1, string &str2)
    {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //initializing the matrix
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
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        //finding the shortest common supersquence
        int i = m, j = n;
        string result;
        while (i > 0 && j > 0)
        {

            //if the characters are same push to the result and move towards diagonally
            if (str1[i - 1] == str2[j - 1])
            {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                //if not then push the non-maximum element to the result and then
                //move to the maximum direction
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    result.push_back(str2[j - 1]);
                    j--;
                }
                else
                {
                    result.push_back(str1[i - 1]);
                    i--;
                }
            }
        }

        //push the rest of the characters
        while (i > 0)
        {
            result.push_back(str1[i - 1]);
            i--;
        }

        //push the rest of the characters
        while (j > 0)
        {
            result.push_back(str2[j - 1]);
            j--;
        }

        //we have to reverse the string to get the desired result
        reverse(result.begin(), result.end());
        return result;
    }
};

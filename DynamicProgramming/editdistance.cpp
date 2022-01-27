/*
Leetcode Question 72. Edit Distance
https://leetcode.com/problems/edit-distance/
*/

/*
This problem is little bit tricky but don't worry we will solve it together.
Basically, after reading the question carefully we can see that we have two choices,
either the character will be same or not same.

So, In the first choice, if the character will be same we don't have to do anything
except for the fact that we have to call the function for the rest of the string.

For the second choice, if the character will not be the same we have three operations
to do inorder to convert the word1 to word2
1. Insert a character
2. Delete a character
3. Replace a character

Now, Let's talk about the operations that we have to perform on word1, I'm trying from
the right side you can try from left also, depends on you.

So, for Insert operation, say for ex - we have two strings
s1 = "abc", s2 = "bcd", m = 3, n = 3 i.e. lengths of the strings respectively
m and n are pointing to the last characters of the string. So we will insert a character 
from right side in s1 and after inserting character string will be "abcd" and the m which 
was pointing to c in s1 will be at the same position but the n which was pointing to d in s2 
now, will point to c in s2 i.e. m, n-1 for the rest of the function calls

Now, for delete operation, same example
s1 = "abc", s2="bcd", m=3, n=3
m and n are pointing to the last characters of the string. Now, after deleting a character
from s1, the m will be m-1, but the n will be same i.e. m-1, n for the rest of the function
calls

Now, for the replace operation, same example
s1 = "abc", s2="bcd", m=3, n=3
m and n are pointing to the last characters of the string. Ultimately, the character at 
corresponding positions in strings will be the same after replacing the character in s1 by
the character in s2, 
ex - "abc", "bcd" => replacing c by d => "abd", "bcd"
Now, call for the rest of the string, so here m will be m-1 and n will be n-1, i.e. m-1, n-1 
for the rest of the function calls

Now, we have to take minimum of all the three operations and add to 1

And Let's talk about base conditions
Example - s1 = "abc", s2 = "bcd", m=3, n=3 lengths of strings respectively
1. if m = 0, then Obviously, we have to insert n characters from s2 in s1 to make s2
2. if n = 0, then Obviously, we have to delete m characters in s1 to make s2
*/

// Recursive
class Solution
{
public:
    // Time: O(min(3^m, 3^n)), Space: O(N);
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        return editDistance(word1, word2, m, n);
    }

    int editDistance(string &word1, string &word2, int m, int n)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        if (word1[m - 1] == word2[n - 1])
            return editDistance(word1, word2, m - 1, n - 1);
        else
        {
            int insertChar = editDistance(word1, word2, m, n - 1);
            int deleteChar = editDistance(word1, word2, m - 1, n);
            int replaceChar = editDistance(word1, word2, m - 1, n - 1);

            return 1 + min({insertChar, deleteChar, replaceChar});
        }
    }
};

// Recursive + Memoization, TopDown Approach
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n);
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        return editDistance(word1, word2, m, n, memo);
    }

    int editDistance(string &word1, string &word2, int m, int n, vector<vector<int> > &memo)
    {
        if (m == 0)
            return memo[m][n] = n;
        if (n == 0)
            return memo[m][n] = m;

        if (memo[m][n] != -1)
            return memo[m][n];

        if (word1[m - 1] == word2[n - 1])
            return memo[m][n] = editDistance(word1, word2, m - 1, n - 1, memo);
        else
        {
            int insertChar = editDistance(word1, word2, m, n - 1, memo);
            int deleteChar = editDistance(word1, word2, m - 1, n, memo);
            int replaceChar = editDistance(word1, word2, m - 1, n - 1, memo);

            return memo[m][n] = 1 + min({insertChar, deleteChar, replaceChar});
        }
    }
};

// BottomUp Approach
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n);
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // Base conditions

        for (int i = 0; i < m + 1; i++)
            dp[i][0] = i;

        for (int j = 0; j < n + 1; j++)
            dp[0][j] = j;

        // solving the sub-problems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    int insertChar = dp[i][j - 1];
                    int deleteChar = dp[i - 1][j];
                    int replaceChar = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({insertChar, deleteChar, replaceChar});
                }
            }
        }
        return dp[m][n];
    }
};

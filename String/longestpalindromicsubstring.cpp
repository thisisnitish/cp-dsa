/*
Leetcode Question 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandFromMiddle(s, i, i);     //racecar
            int len2 = expandFromMiddle(s, i, i + 1); //aabbaa

            int maxLength = max(len1, len2);

            if (maxLength > end - start)
            {
                start = i - ((maxLength - 1) / 2);
                end = i + (maxLength / 2);
            }
        }
        return (s.substr(start, end - start + 1));
    }

    int expandFromMiddle(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right))
        {
            left--;
            right++;
        }
        return (right - left - 1);
    }
};
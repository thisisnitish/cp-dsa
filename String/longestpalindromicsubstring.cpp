/*
Leetcode Question 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/

/*
The first intuition is to solve this via Longest Common Substring, but unfortunately,
this is not the right way of doing it.
*/

class Solution
{
public:
    //Time: O(N^2)
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;

        //The idea is take every character from the string get traverse 
        //backward and forward to get and compare the character and the length simultaneously
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandFromMiddle(s, i, i);     //racecar i.e. when the string is of length odd
            int len2 = expandFromMiddle(s, i, i + 1); //aabbaa i.e.when the string is of length even

            int maxLength = max(len1, len2);

            if (maxLength > end - start)
            {
                start = i - ((maxLength - 1) / 2);
                end = i + (maxLength / 2);
            }
        }
        return (s.substr(start, end - start + 1));
    }

    // utility function to check whether the string is palindrome or not
    // but it is expanding from the middle of the string
    int expandFromMiddle(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return (right - left - 1);
    }
};
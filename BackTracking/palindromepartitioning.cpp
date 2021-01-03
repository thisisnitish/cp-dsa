/*
Leetcode Question 131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution
{
public:
    /* the idea is check every substring one by one
    if it is palindrome then put it into the result*/
    bool isPalindrome(string s)
    {
        string temp = s;
        reverse(temp.begin(), temp.end());
        if (s.compare(temp) == 0)
            return true;
        return false;
    }

    void allpalindrome(vector<vector<string>> &result, string s, int start, vector<string> &help)
    {

        if (start >= s.size())
        {
            /*here when start will reach the end 
            of string then push to the result*/
            result.push_back(help);
            return;
        }

        for (int i = start; i < s.length(); i++)
        {
            string util = s.substr(start, i - start + 1);
            if (isPalindrome(util))
            {

                //if the substring is palindrome then push to the help
                help.push_back(util);

                allpalindrome(result, s, i + 1, help);

                /*backtracking and remove the
                current substring partition
                i.e. after multiple function calls 
                all the function will return
                here so one by one pop every element 
                and make the array empty for next operation*/
                help.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result; //output
        vector<string> help;           //help is to store the current partition
        allpalindrome(result, s, 0, help);
        return result;
    }
};
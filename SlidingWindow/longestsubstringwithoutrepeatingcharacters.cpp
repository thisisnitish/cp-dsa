/*
Leetcode Question 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int i = 0, j = 0, result = INT_MIN;
        unordered_map<char, int> mp;
        while (j < s.size())
        {

            //calculation I
            mp[s[j]]++;

            if (mp.size() < j - i + 1)
            {
                while (mp.size() < j - i + 1)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if (mp.size() == j - i + 1)
            {
                //calculation II
                result = max(result, j - i + 1);
                j++;
            }
            /*mp.size() will never be more than j-i+1 becaause mp stores unique chars and
            atmost it can store the entire window*/
        }
        return result;
    }
};

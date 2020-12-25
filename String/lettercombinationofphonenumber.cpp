/*
Leetcode Question 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution
{
public:
    //can also be done using recursion
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result{""};

        for (int i = 0; i < digits.length(); i++)
        {
            char c = digits[i];

            vector<string> temp;
            string s = mp.at(c);

            for (auto item1 : result)
            {
                for (auto item2 : s)
                {
                    temp.push_back(item1 + item2);
                }
            }

            result.clear();
            result = temp;
        }
        return result;
    }
};
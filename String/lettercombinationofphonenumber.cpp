/*
Leetcode Question 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution
{
public:
    //can also be done using recursion
    //O(n^3)
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        
        
        //using map to store the all possible values of all digits
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
            char c = digits[i];  //here taking the every character from the digit strings

            vector<string> temp;
            string s = mp.at(c);   // getting the specific string from the map according to the character

            for (auto item1 : result)
            {
                for (auto item2 : s)
                {
                    //concatenate here both i.e. items 
                    //from the string and result respectively
                    temp.push_back(item1 + item2);
                }
            }

            result.clear();     //first clear the result and then get the actual value because the previous value will not necessary
            result = temp;
        }
        return result;
    }
};
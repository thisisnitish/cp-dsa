/*
Leetcode Question 205. Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/
*/

/*
Insert chars of string s as key, and chars of t as value , into a map. For ex. if s = foo and t = baa 
contents of map should be'f'-'b' , 'o'-'a'.

if present check for the values of the corresponding chars in t and map's value, i.e map[s[i]] != 
t[i] return false else continue to next index.

The above steps work for the given eg. test cases, but for s= badc and t = baba the map results in 
the following content:'b'-'b' , 'a'-'a' , 'd'-'a', 'c'-'a' and return true as answer.

So to avoid test cases having "many to one" key value pair, the function is called by interchanging s 
and t , for the above case now s= baba and t= badcwhen characterb of string s is processed for the 
second time map[s[i]] = b but t[i]= d which are not same, hence returns false.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    bool isIsomorphic(string s, string t)
    {
        return (helper(s, t) && helper(t, s));
    }

    int helper(string s, string t)
    {
        unordered_map<char, char> mp;

        int n = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                if (mp[s[i]] != t[i])
                    return false;
            }
            else
                mp[s[i]] = t[i];
        }
        return true;
    }
};

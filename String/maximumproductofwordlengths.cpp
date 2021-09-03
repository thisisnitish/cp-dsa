/*
Leetcode Question 318. Maximum Product of Word Lengths
https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

//Brute Force
class Solution
{
public:
    //Time: O(N*M*T + K), Space: O(K)
    int maxProduct(vector<string> &words)
    {
        int result = INT_MIN, flag = 0;

        for (int i = 0; i < words.size() - 1; i++)
        {
            string temp = words[i];
            unordered_map<char, int> mp;
            for (auto t : temp)
                mp[t]++;

            for (int j = i + 1; j < words.size(); j++)
            {
                string residue = words[j];

                for (auto r : residue)
                {
                    if (mp.find(r) != mp.end())
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    int l = temp.size() * residue.size();
                    result = max(result, l);
                }
                flag = 0;
            }
        }
        return result == INT_MIN ? 0 : result;
    }
};

//Optmized
class Solution
{
public:
    //Time: O(n*(N+n)), Space: O(N)
    int maxProduct(vector<string> &words)
    {
        int n = words.size(), result = 0;

        //it will store the chars which occurs in a particular word
        vector<bitset<26> > chars(n);

        for (int i = 0; i < n; i++)
        {
            //when the char occurs in word mark as true
            for (auto ch : words[i])
                chars[i][ch - 'a'] = 1;

            //check with all other words, if there is no common letter return the answer
            for (int j = 0; j < i; j++)
            {
                if (!checkCommon(chars[i], chars[j]))
                {
                    int l = words[i].size() * words[j].size();
                    result = max(result, l);
                }
            }
        }
        return result;
    }

    bool checkCommon(bitset<26> &a, bitset<26> &b)
    {
        for (int i = 0; i < 26; i++)
            if (a[i] && b[i])
                return true;
        return false;
    }
};

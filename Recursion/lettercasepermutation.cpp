/*
Leetcode Question 784. Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/
*/

class Solution
{
public:
    // Time: O(2^N), Space: O(2^N)
    vector<string> allpermutations;
    void findPermutations(string s, string permutation)
    {
        // base case
        if (s.size() == 0)
        {
            allpermutations.push_back(permutation);
            return;
        }

        if (isalpha(s[0]))
        {
            string permutation1 = permutation;
            string permutation2 = permutation;

            /*
            as the question says,you can transform every letter individually to be
            lowercase or uppercase to create another string. So, we have 2 choices,
            if we encounter an alphabet.
            */

            permutation1.push_back(toupper(s[0]));
            permutation2.push_back(tolower(s[0]));

            s.erase(s.begin() + 0);

            findPermutations(s, permutation1);
            findPermutations(s, permutation2);
        }
        else
        {
            string permutation1 = permutation;
            permutation1.push_back(s[0]);

            s.erase(s.begin() + 0);

            findPermutations(s, permutation1);
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        string permutation;
        findPermutations(s, permutation);
        return allpermutations;
    }
};

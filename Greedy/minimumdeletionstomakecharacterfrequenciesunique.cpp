/*
Leetcode Question 1647. Minimum Deletions to Make Character Frequencies Unique
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/

/*
It's clear that it would be useful to have the count of each character because that's how we 
will determine if a string is good. A map is a natural choice for doing this.

Now we want to figure out if we've seen a given count before. A set is a natural data 
structure for keeping track of what we've seen. So we go through our counts and insert any 
new un-seen numbers into the set. If we've seen a certain count before, we decrement it until 
we haven't seen it before.

We just need to be careful with 0. Imagine if our frequencies are all 1. We put the first 1 
into our set. Then we decrement the second 1 to avoid a collision. So that count became 0, 
which means we don't have the associated letter at all anymore. We shouldn't put 0 into our 
set because otherwise the next 1 would need to be decremented twice to become unique, which 
doesn't make sense. Once we get to 0, we stop decrementing because the letter doesn't exist 
anymore.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int minDeletions(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }

        int count = 0;
        unordered_set<int> seen;

        for (auto [k, v] : mp)
        {
            while (seen.find(v) != seen.end())
            {
                v--;
                count++;
            }
            if (v > 0)
                seen.insert(v);
        }
        return count;
    }
};

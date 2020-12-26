/*
Leetcode 1662. Check If Two String Arrays are Equivalent
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string Word1 = "";
        string Word2 = "";

        for (auto item : word1)
        {
            Word1 += item;
        }

        for (auto item : word2)
        {
            Word2 += item;
        }
        //cout<<Word1<<" "<<Word2<<endl;
        if (Word1.compare(Word2) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
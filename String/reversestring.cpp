/*
Leetcode Question 344. Reverse String
https://leetcode.com/problems/reverse-string/
*/
/*You can go with the reverse inbuilt function also in C++*/
class Solution
{
public:
    /*Time: O(N), Space: O(1)*/
    void reverseString(vector<char> &s)
    {
        int size = s.size();
        for (int i = 0; i < size / 2; i++)
        {
            int temp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = temp;
        }
    }
};
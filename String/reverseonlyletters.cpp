/*
Leetcode Question 917. Reverse Only Letters
https://leetcode.com/problems/reverse-only-letters/
*/

//Solution 1
class Solution
{
public:
    //Time: O(N), Space: O(N)
    string reverseOnlyLetters(string s)
    {
        stack<char> st;

        for (auto c : s)
        {
            if (isalpha(c))
                st.push(c);
        }
        string result;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                result.push_back(st.top());
                st.pop();
            }
            else
                result.push_back(c);
        }
        return result;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(N), Space: O(1)
    string reverseOnlyLetters(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {

            //for left
            bool check1 = (s[left] >= 'a' && s[left] <= 'z') ||
                          (s[left] >= 'A' && s[left] <= 'Z');
            //for right
            bool check2 = (s[right] >= 'a' && s[right] <= 'z') ||
                          (s[right] >= 'A' && s[right] <= 'Z');
            if (check1 && check2)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (check1 == true && check2 == false)
            {
                right--;
            }
            else if (check1 == false && check2 == true)
            {
                left++;
            }
            else if (check1 == false && check2 == false)
            {
                left++;
                right--;
            }
        }
        return s;
    }
};

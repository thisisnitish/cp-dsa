/*
Leetcode Question 71. Simplify Path
https://leetcode.com/problems/simplify-path/
*/

class Solution
{
public:
    // Time: O(N), Space: O(N)
    string simplifyPath(string path)
    {
        stack<string> st;
        int n = path.size();
        if (path[path.size() - 1] != '/')
            path.push_back('/');

        string temp = "";
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (temp == "" || temp == ".")
                {
                } // do nothing
                else if (temp == "..")
                {
                    if (st.size() > 0)
                        st.pop();
                }
                else
                    st.push(temp);
                temp = "";
            }
            else
            {
                temp.push_back(path[i]);
            }
        }

        string res = "";
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if (res == "")
            return "/";
        return res;
    }
};

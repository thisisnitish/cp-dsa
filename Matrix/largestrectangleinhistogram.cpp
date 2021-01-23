/*
Leetcode Question 84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution
{
public:
    /*the basic idea is to make a left and right array
    just to create a limits from left and right for each
    bar and the finding the area for each bar and return
    the maximum area. Time: O(N)*/
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> left(n), right(n);

        stack<int> st;

        //filing the left array
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left[i] = 0;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                left[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
            }
        }

        /*here we we've cleared the stack
        inorder to reuse it but we can create
        another but that will be a waste of memory*/
        while (!st.empty())
        {
            st.pop();
        }

        //filing the right array
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                right[i] = n - 1;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                right[i] = st.empty() ? n - 1 : st.top() - 1;
                st.push(i);
            }
        }

        /*finding the maxArea*/
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }
        return maxArea;
    }
};
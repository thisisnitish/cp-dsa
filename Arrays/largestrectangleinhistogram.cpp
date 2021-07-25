/*
Leetcode Question 84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

/*
Watch this for more clear explanation
https://www.youtube.com/watch?v=vcv3REtIvEo

If you observe, atleast one bar will be fully included in the largest rectangle
if largest rectangle contains atleast 1 bar in full then if we find areas of all largest 
rectangles for each bar being fully included full then we can find the maximum rectangle 
area

Solution steps
1. find largest rectangle including each bar one by one
2. Take maximum of all the max areas for each bar found

For each bar we need to decide the left and right boundary.

In order to calculate the left boundary, we will be using left array to store the left
boundary for each bar and also stack to maintain the index for each bar.

If the stack is empty then directly push the index to the stack also push 0 to the left
because we have reached the extreme left of the array.

If the stack is not empty, then for every current bar we will compare with the previous
bar if the current bar is small then pop index from the stack else don't.

Also if the stack will be empty that means we have reached to the extreme left so push
0 to that specific left bar. If the stack still is not empty then take the top element
from the stack and add 1 to it.

Similary, we need to do for setting the right boundary

Todo: Still needs a clear explanation
*/

class Solution
{
public:
    /*the basic idea is to make a left and right array
    just to create a limits from left and right for each
    bar and the finding the area for each bar and return
    the maximum area. Time: O(N), Space: O(N)*/
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        //stores the left and right limits for each bar
        vector<int> left(n), right(n);

        stack<int> st; //stores the indices

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
                //check the current bar with the previous bar
                while (!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }

                left[i] = st.empty() ? 0 : st.top() + 1; //sets the left limit for each bar
                st.push(i);
            }
        }

        /*here we we've cleared the stack
        inorder to reuse it but we can create
        another but that will be a waste of memory*/
        while (!st.empty())
            st.pop();

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
                //check the current bar with the previous bar
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

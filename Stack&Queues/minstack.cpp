/*
Leetcode Question 155. Min Stack
https://leetcode.com/problems/min-stack/
*/

/*
This question was pretty tricky to me. I missed one thing that, I need to keep track
of the min till every number which is pushed in the stack.

Whenever a number gets popped from stack the minimum changes.

So, We designed the stack in such a way that we can track minimum till every number.
*/

class MinStack
{
public:
    // Time: O(N), Space: O(N)
    vector<pair<int, int>> v;
    MinStack()
    {
    }

    void push(int val)
    {
        if (v.size() == 0)
            v.push_back({val, val});
        else
            v.push_back({val, min(v[v.size() - 1].second, val)});
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1].first;
    }

    int getMin()
    {
        return v[v.size() - 1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

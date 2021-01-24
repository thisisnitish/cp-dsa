/*
Leetcode Question 232. Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue
{
public:
    /*here the question says to use 2 stacks, 
    the dequeue operation is costly here.
    Time: Push O(1), Pop O(N), Space: O(N)*/
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int top = peek();
        s2.pop();
        return top;
    }

    /** Get the front element. */
    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
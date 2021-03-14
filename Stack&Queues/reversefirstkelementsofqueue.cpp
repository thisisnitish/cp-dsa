/*
Reverse First K elements of Queue
https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#
*/

/*the basic idea is to pop the k values from q and
push to the stack and pop again from the s push to the temp
and at the end push rest of values from q to temp
Time: O(N), Space: O(N)*/
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> s;
    queue<int> temp;

    while (k--)
    {
        int x = q.front();
        q.pop();
        s.push(x);
    }

    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        temp.push(x);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        temp.push(x);
    }
    return temp;
}
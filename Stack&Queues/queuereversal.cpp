/*
Queue Reversal
https://practice.geeksforgeeks.org/problems/queue-reversal/1#
*/

/*the basic idea is to recurse the queue and at last
start pushing the value. Time: O(N)*/
void helper(queue<int> &q)
{
    if (q.empty())
        return;

    int temp = q.front();
    q.pop();

    helper(q);
    q.push(temp);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    helper(q);
    return q;
}
